

#include "atom.h"
#include "variable.h"
#include "struct.h"
#include <typeinfo>

bool Term::match(Term & a){
    if (typeid(a) ==  typeid(Variable))
      return a.match(*this);
    else
      return symbol() == a.symbol();
    if(typeif(a) == typeid(Struct))
        return a.match(*this);
    else
        return symbol() == a.symbol();
  }
  