#include "number.h"
#include "atom.h"
#include "variable.h"


bool Variable::match(Atom atom){

    if(value=="")
    {   
      value = atom.symbol;
      
      assignable = false;
      return true; 
    }
    else if(value!=""){
        if(value == atom.symbol)
            return true;
        else
            return false;
    }
}
bool Variable::match(Number n){

    if(value=="")
    {
      value = n.symbol;
      
      assignable = false;
      return true; 
    }
    else if(value!=""){
        if(value == n.symbol)
            return true;
        else
            return false;
    }
}
