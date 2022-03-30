#include <sstream>
#include <string>

using namespace std;

enum class Option{LookAndSay, Reflect};
enum class ConversionStatus{Done, InvalidInput};

pair<string, ConversionStatus> Convert(const string &input, Option option) {
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
