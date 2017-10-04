
#include <iostream>
#include "number.h"
#include "atom.h"
#include "variable.h"

bool Atom::match(Number n){
    return false;
}
bool Atom::match(Variable &v){
    
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