#include<string>
#include "number.h"
#include "atom.h"
#include "variable.h"
#include <iostream>

bool Number::match(Number n)
{
  if(n.num == num)
  return true;
  else
  return false;
}
bool Number::match(Atom atom)
{
  return false;
}
bool Number::match(Variable &v)
{
  if(v.num=="")
  {
      
    v.num = num;
    v.symbol = sym;
  }
  else if(v.num!=""){
      if(v.num == num)
          return true;
      else
          return false;
  }
}

