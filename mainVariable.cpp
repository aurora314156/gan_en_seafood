#include "number.h"
#include "atom.h"
#include "variable.h"


bool Variable::match(Atom atom){

    if(symbol=="X")
    {
        symbol = atom.symbol;
      value = atom.value;
      return true;
   
    }
    else if(symbol!="X"){
        if(value == atom.value)
            return true;
        else
            return false;
    }
}
bool Variable::match(Number n){

    if(symbol=="X")
    {
      value = n.num;
      symbol = n.sym;
     
    }
    else if(symbol!="X"){
        if(value == n.num)
            return true;
        else
            return false;
    }
}
