#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "number.h"

using std::string;

class Number;
class Atom;

class Variable{

public:

    Variable(string s):symbol(s){}
    string symbol="";
    string num="";
    
    string value(){ return num; }
    bool match(Atom atom);
    bool match(Number n);
    
  
};

#endif
