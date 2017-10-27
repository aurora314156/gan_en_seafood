#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
using namespace std;

class Variable : public Term {
public:

  Variable (string s);
  string value() const;
  bool match(Term &term);
private:
  Term * _inst;


  /*
  Variable(string s):Term(s), _inst(0){}
  string value() const {
    if (_inst)
      return _inst->value();
    else
      return Term::value();
  }
  bool match( Term & term ){
    if (this == &term)
      return true;
    if(!_inst){
      _inst = &term ;
      return true;
    }
    return _inst->match(term);
  }
private:
  Term * _inst;*/
};
//X = 1,X = Y
#endif
