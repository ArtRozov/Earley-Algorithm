#include "include/Earley.h"
#include <gtest/gtest.h>

TEST(Earley, CheckOperator1) {
  Rule rule = std::make_pair('S', "ABA");
  Earley::Situation first(rule, 1, 0);
  Earley::Situation second(rule, 1, 1);
  ASSERT_EQ(first < second, true);
}

TEST(Earley, CheckOperator2) {
  Rule rule = std::make_pair('S', "ABA");
  Earley::Situation first(rule, 0, 0);
  Earley::Situation second(rule, 1, 1);
  ASSERT_EQ(first < second, true);
}

TEST(Earley, CheckOperator3) {
  Rule rule1 = std::make_pair('A', "ABA");
  Rule rule2 = std::make_pair('S', "TBA");
  Earley::Situation first(rule1, 1, 0);
  Earley::Situation second(rule2, 1, 1);
  ASSERT_EQ(first < second, true);
}

TEST(Earley, CheckTrueParse){
  std::vector<char> N = {'T', 'S'};
  std::vector<char> sigma = {'a', 'b'};
  std::vector<Rule> P = {{'T', "S"}, {'S', ""}, {'S', "aSbSbS"}};
  char S = 'T';
  Grammar grammar(N, sigma, P, S);
  Earley parser(grammar);
  ASSERT_EQ(parser.Parse("aabbbb"), true);
}

TEST(Earley, CheckFalseParse){
  std::vector<char> N = {'T', 'S'};
  std::vector<char> sigma = {'a', 'b'};
  std::vector<Rule> P = {{'T', "S"}, {'S', ""}, {'S', "aSbSbS"}};
  char S = 'T';
  Grammar grammar(N, sigma, P, S);
  Earley parser(grammar);
  ASSERT_EQ(parser.Parse("aaabbbb"), false);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
