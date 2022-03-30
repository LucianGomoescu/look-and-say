#include "LookAndSay.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
  if(argc != 3) {
    cout<<"Command accepts only two arguments."<<endl;
    return -1;
  }

  string option(argv[1]);
  char* value = argv[2];

  if (option == "-l") {
    auto answer = Convert(value, Option::LookAndSay);
    cout << ((answer.second == ConversionStatus::Done) ?
    answer.first : "Invalid value")<<endl;
  } else if (option == "-r") {
    auto answer = Convert(value, Option::Reflect);
    cout << ((answer.second == ConversionStatus::Done) ?
    answer.first : "Invalid value")<<endl;
  } else {
    cout << "Unrecognized option (allowed values: '-l' or '-r')"<<endl;
  }
  return 0;
}
