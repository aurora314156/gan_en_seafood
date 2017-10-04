#include "number.h"
#include "atom.h"
#include "variable.h"
#include <iostream>


bool Number::match(Atom atom)
{
  return false;
}
bool Number::match(Variable &v)
{
  if(v.value=="")
  {
      
    v.value = symbol;
    
    assignable = false;
    return true; 
  }
  else if(v.value!=""){
      if(v.value == symbol)
          return true;
      else
          return false;
  }
}

