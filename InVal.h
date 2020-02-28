//InVal.h

//#ifndef INVAL_H
//#define INVAL_H

#include <string>

class InVal {
private:
  std::string input;
  int base10;
  std::string output;
public:
  InVal();
  void PrintAsBase(int);
  void InputNum(std::string, int);
};

//#endif
