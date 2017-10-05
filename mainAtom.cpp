
#include <iostream>
#include "number.h"
#include "atom.h"
#include "variable.h"

bool Atom::match(Number n){
    return false;
}
bool Atom::match(Variable &v){
    
    if(v.symbol=="X")
    {
      v.symbol = symbol;
      v.value = value;
      
    }
    else if(v.symbol!="X"){
        if(v.value == value)
            return true;
        else
            return false;
    }
}