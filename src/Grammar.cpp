#include "../include/Grammar.h"

bool Grammar::SetNonTerminal(char c) {
  if (std::find(non_terminal.begin(), non_terminal.end(), c) == non_terminal.end()) {
    non_terminal.push_back(c);
    return true;
  }
  return false;
}

void Grammar::SetRule(const Rule& rule) {
  if (std::find(non_terminal.begin(), non_terminal.end(), rule.first) == non_terminal.end()) {
    non_terminal.push_back(rule.first);
  }
  rules.push_back(rule);
}

void Grammar::AddRule(const std::string& s) {
  std::string right;
  for (size_t i = 3; i < s.length(); ++i) {
    right += s[i];
  }
  SetRule(std::make_pair(s[0], right));
}

void Grammar::ReadGrammar() {
  std::cout << "Set number of non-terminals\n";
  size_t n;
  std::cin >> n;
  assert(n <= 26);
  for (size_t i = 0; i < n; ++i) {
    std::cout << "Input non-terminal: ";
    char non_term;
    std::cin >> non_term;
    std::cout << non_term << '\n';
    while (!SetNonTerminal(non_term)) {
      std::cout << "Wrong input! This non_terminal exists, try again\n";
      std::cin >> non_term;
    }
    std::cout << non_term << " installed!\n";
  }
  std::cout << "Set number of terminals\n";
  std::cin >> n;
  for (size_t i = 0; i < n; ++i) {
    std::cout << "Input terminal: ";
    char term;
    std::cin >> term;
    std::cout << term << '\n';
    terminal.push_back(term);
    std::cout << term << " installed!\n";
  }
  std::cout << "Reminder: first rule is always rule A->B where A - start\n"
            << "Another rules are like in example\nExample of rule: S->aBdASBbfk\n"
            << "Set number of rules\n";
  std::cin >> n;
  for (size_t i = 0; i < n; ++i) {
    std::string rule;
    std::cout << "Input rule: ";
    std::cin >> rule;
    std::cout << rule << '\n';
    if (i == 0) { start = rule[0]; }
    AddRule(rule);
  }
  std::cout << "We finished to read grammar!\n";
}

std::vector<Rule> Grammar::GetRules() const {
  return rules;
}

