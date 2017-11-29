#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <sstream>
#include "term.h"
using std::string;



class Atom : public Term{
public:
  Atom(string s):Term(s) {}
  bool match(Term &a)
  {
    if(a.isList)
    return false;
    else
    return _symbol == a.symbol();

  }
  bool isAtom = true;
};


#endif
