#include "term.h"


string Term::value() const{
    return symbol();
}

bool Term::match(Term &term){

    return symbol() == term.symbol();
}