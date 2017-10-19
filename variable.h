#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include "term.h"
#include "atom.h"
#include "number.h"
#include "struct.h"

using namespace std;


class Variable: public Term{

    public:
    Variable(string s):_symbol(s),_value(s){}
    
    string  value() const {
        if(str!=0)
            return str->value();
        else
            return _value; 
    }
    string  symbol() const {
        return _symbol;
    }
    bool match(Term &term);
  
    string _symbol;
    string _value;
    bool _sign = true;
    vector<Variable *> vec;
    Struct* str=0;
    
    
};
#endif