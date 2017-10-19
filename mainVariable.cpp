#include "number.h"
#include "atom.h"
#include "variable.h"
#include "struct.h"


bool Variable::match(Term &term){

    if(_sign || _value==term.symbol()){
        //v.push_back(&term);
        _sign = false;
        _value = term.symbol();
        return true;
    }
    /*if(v.size()!=0)
    {
        v[0]->symbol() = term.symbol();
        return true;
    }*/
    return false;
}


//x=y,x=tom
//y=tom