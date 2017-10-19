#include "atom.h"
#include "variable.h"

Atom :: Atom (string s) : _symbol (s),_value(s) {}

bool Atom::match(Term &term){

	Variable* v = dynamic_cast <Variable*> (&term);
    
    if (v)
        return v -> match (*this);
	else	
        return _symbol == term.symbol();
}