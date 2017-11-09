#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
using std::string;

class Variable : public Term {
public:
  //Variable(string s):Term(s), _inst(0){}
  Variable(string s);
  string value() const ;
  bool match( Term & term );
  
private:
  Term * _inst;
};

#endif
