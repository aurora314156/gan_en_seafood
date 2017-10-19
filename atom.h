#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "term.h"

using namespace std;

class Atom : public Term{

public:

    Atom (string s);

    string symbol () const{
        return _symbol;

    };
    string value ()const{
        return _value;
    };

    bool match ( Term &term );

    string _symbol;
    string _value;

};
#endif
