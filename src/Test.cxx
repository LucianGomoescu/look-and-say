#include "Test.h"

#include "LookAndSay.h"

#include <vector>

vector<string> gl_numbers = {"1", "331", "55", "2514", "33345005"};
vector<string> gl_sequences = {"11", "2311", "25", "12151114", "3314152015"};
vector<string> gl_badValues = {"-1", "5.7"};

TestStatus TestNumberToSequence::Run() {
  int i = 0;
  for (auto &num : gl_numbers) {
    auto answer = Convert(num, Option::LookAndSay);
    auto sequence = answer.first;
    auto status = answer.second;
    if ((sequence != gl_sequences[i]) || (status != ConversionStatus::Done)) {
      return TestStatus::Failed;
    }
    i++;
  }
  return TestStatus::Passed;
}

TestStatus TestSequenceToNumber::Run() {
  int i = 0;
  for (auto &seq : gl_sequences) {
    auto answer = Convert(seq, Option::Reflect);
    auto number = answer.first;
    auto status = answer.second;
    if ((number != gl_numbers[i]) || (status != ConversionStatus::Done)) {
      return TestStatus::Failed;
    }
    i++;
  }
  return TestStatus::Passed;
}

TestStatus TestOddLengthSequenceToNumber::Run() {
  auto answer = Convert("135", Option::Reflect);
  return ((answer.second == ConversionStatus::InvalidInput) ?
          TestStatus::Passed : TestStatus::Failed);
}

TestStatus TestBadValues::Run() {
  vector<Option> options = { Option::LookAndSay, Option::Reflect };
  for (auto option : options) {
    int i = 0;
    for (auto &input : gl_badValues) {
      auto answer = Convert(input, option);
      auto status = answer.second;
      if (status != ConversionStatus::InvalidInput) {
        return TestStatus::Failed;
      }
      i++;
    }
  }
  return TestStatus::Passed;
}
