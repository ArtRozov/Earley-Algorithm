#include "Grammar.h"

class Earley {
 public:
  Earley(const Grammar& grammar) : grammar(grammar) {}

  bool Parse(const std::string&);

  struct Situation {
    Rule rule;
    size_t point;
    size_t i;

    Situation(Rule rule, size_t point, size_t i) : rule(rule), point(point), i(i) {};

    bool operator<(const Situation& another) const {
      if (rule == another.rule) {
        if (point == another.point) {
          return i < another.i;
        }
        return point < another.point;
      }
      return rule < another.rule;
    }
  };

  std::string w;
  std::vector<std::set<Situation>> D;
  Grammar grammar;

  void Predict(size_t);

  void Scan(size_t, char);

  void Complete(size_t j);
};

