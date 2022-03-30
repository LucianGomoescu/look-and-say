#include <cassert>
#include <sstream>
#include <string>

using namespace std;

enum class Option{LookAndSay, Reflect};
enum class ConversionStatus{Done, InvalidInput};

pair<string, ConversionStatus> ConvertToSequence(const string &input) {
  stringstream output;
  for (auto const &c : input) {
    if (isdigit(c) == 0) { // not a digit
      return make_pair(output.str(), ConversionStatus::InvalidInput);
    }
  }

  int end = input.length();
  int pos = 0;
  char sym = input[pos];
  int counter = 0;

  for (auto const &c : input) {
      if (pos == end - 1) { // reached the end
        if (c == sym) {
          counter++;
          output << counter;
          output << sym;
        } else {
          output << counter;
          output << sym;
          output << 1 << c;
        }
      } else {
        if (c == sym) {
          counter++;
        } else {
          output << counter;
          output << sym;
          sym = input[pos];
          counter = 1;
        }
      }
    pos++;
  }
  return make_pair(output.str(), ConversionStatus::Done);
}

pair<string, ConversionStatus> ConvertToNumber(const string &input) {
  stringstream output;
  for (auto const &c : input) {
    if (isdigit(c) == 0) { // not a digit
      return make_pair(output.str(), ConversionStatus::InvalidInput);
    }
  }

  if(input.length() % 2 != 0) { // the input sequence must be even
    return make_pair(output.str(), ConversionStatus::InvalidInput);
  }

  auto n = input.length();
  int i = 0;
  while (i < n) {
    int counter = int(input[i]) - 48; // convert char to int
    char sym = input[i+1];
    for (int j = 0; j < counter; ++j) {
      output<<sym;
    }
    i += 2;
  }
  return make_pair(output.str(), ConversionStatus::Done);
}

pair<string, ConversionStatus> Convert(const string &input, Option option) {
  switch(option) {
    case Option::LookAndSay:
      return ConvertToSequence(input);
    case Option::Reflect:
      return ConvertToNumber(input);
    default:
      assert(false);
  }
}
