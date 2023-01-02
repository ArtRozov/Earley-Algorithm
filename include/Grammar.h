#include <vector>
#include <iostream>
#include <set>
#include <cassert>

using Rule = std::pair<char, std::string>;

class Grammar {
 private:
  std::vector<char> non_terminal;
  std::vector<char> terminal;
  std::vector<Rule> rules;
  char start;
 public:

  Grammar() = default;

  Grammar(const std::vector<char>& non_terminal, const std::vector<char>& terminal,
          const std::vector<Rule>& rules, char start) : non_terminal(non_terminal), terminal(terminal),
                                                        rules(rules), start(start) {}

  bool SetNonTerminal(char c);

  void SetRule(const Rule&);

  void AddRule(const std::string&);

  void ReadGrammar();

  std::vector<Rule> GetRules() const;
};
