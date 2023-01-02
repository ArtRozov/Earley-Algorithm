#include "../include/Earley.h"

bool Earley::Parse(const std::string& s) {
  w = s;
  D.clear();
  D.resize(w.size() + 1);
  D[0].insert(Situation(grammar.GetRules()[0], 0, 0));
  size_t current_size = D[0].size();
  Predict(0);
  Complete(0);
  while (D[0].size() != current_size) {
    current_size = D[0].size();
    Predict(0);
    Complete(0);
  }
  for (size_t i = 1; i <= w.size(); ++i) {
    Scan(i - 1, w[i - 1]);
    current_size = D[i].size();
    Predict(i);
    Complete(i);
    while (D[i].size() != current_size) {
      current_size = D[i].size();
      Predict(i);
      Complete(i);
    }
  }
  return D[w.size()].find(Situation(grammar.GetRules()[0], 1, 0)) != D[w.size()].end();
}

void Earley::Predict(size_t j) {
  std::vector <Situation> new_situations;
  for (auto situation: D[j]) {
    for (auto rule: grammar.GetRules()) {
      if (rule.first == situation.rule.second[situation.point]) {
        new_situations.push_back(Situation(rule, 0, j));
      }
    }
  }
  for (auto situation: new_situations) {
    D[j].insert(situation);
  }
}

void Earley::Scan(size_t j, char x) {
  for (auto situation: D[j]) {
    if (situation.rule.second[situation.point] == x) {
      D[j + 1].insert(Situation(situation.rule, situation.point + 1, situation.i));
    }
  }
}

void Earley::Complete(size_t j) {
  std::vector <Situation> new_situations;
  for (auto situation_a: D[j]) {
    if (situation_a.point != situation_a.rule.second.size()) continue;
    for (auto situation_b: D[situation_a.i]) {
      if (situation_b.rule.second[situation_b.point] == situation_a.rule.first) {
        new_situations.push_back(Situation(situation_b.rule, situation_b.point + 1, situation_b.i));
      }
    }
  }
  for (auto situation: new_situations) {
    D[j].insert(situation);
  }
}
