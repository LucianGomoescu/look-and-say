#include "Test.h"

#include "LookAndSay.h"

#include <vector>

vector<string> gl_numbers = {"1", "331", "55", "2514", "33345005"};
vector<string> gl_sequences = {"11", "2311", "25", "12151114", "3314152015"};

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
  return TestStatus::Failed;
}
