#include "number.h"
#include "variable.h"
#include <string>
#include <iostream>
#include <sstream>

Number::Number(double s ){

    std::stringstream st;
    
    st<<s;

    _symbol = st.str();
    _value = st.str();

}

bool Number::match(Term &term){

	Variable* v = dynamic_cast<Variable*> (&term);
    
    if(v)
        return v->match(*this);
	else
        return _symbol == term.symbol();
}