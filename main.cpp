#include "include/Earley.h"

int main(){
  Grammar grammar;
  grammar.ReadGrammar();
  std::string word;
  std::cout << "Enter the word\n";
  std::cin >> word;
  Earley parser(grammar);
  if (parser.Parse(word)) {
    std::cout << "\nYes, this word belongs to grammar language\n\n";
  } else {
    std::cout << "\nNo, this word doesn't belongs to grammar language\n\n";
  }
  std::cout << "Press Ctrl+D to start checking test-coverage!\n";
  std::cin >> word;
  return 0;
}