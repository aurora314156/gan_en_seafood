#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "variable.h"
#include "number.h"


using namespace std;

class Number;
class Variable;

class Atom {

public:
  Atom (string s):symbol(s),value(s) {}
  
  string symbol;
  string value;
  
  
  bool match(Number n);
  bool match(Variable &v);

};

#endif
