#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include "term.h"
#include "atom.h"
#include "number.h"

using namespace std;

class Number;
class Atom;

class Variable: public Term{

    public:
    Variable(string s):_symbol(s),_value(s){}
    
    string  value()const {
         return _value; 
    }
    string  symbol()const {
        return _symbol;
    }
    bool match(Term &term);
  
    string _symbol;
    string _value;
    vector<Term *> v;
    bool _sign = true;
    
};
#endif