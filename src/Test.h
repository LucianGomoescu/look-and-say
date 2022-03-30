#include <string>

enum class TestStatus{Passed, Failed};

using namespace std;

class ITest {
public:
  virtual TestStatus Run() = 0;
  virtual string GetName() = 0;
};

class TestNumberToSequence : public ITest {
public:
  string GetName() override { return "convert number to sequence"; }
  TestStatus Run() override;
};

class TestSequenceToNumber : public ITest {
public:
  string GetName() override { return "convert sequence to number"; }
  TestStatus Run() override;
};

class TestOddLengthSequenceToNumber : public ITest {
public:
  string GetName() override { return "odd length sequence to number"; }
  TestStatus Run() override;
};

class TestBadValues : public ITest {
public:
  string GetName() override { return "bad values to sequence/number"; }
  TestStatus Run() override;
};
