#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "term.h"

using namespace std;

class Atom : public Term{

public:

    Atom (string s);

    string symbol () const;
    string value ()const;

    string _symbol;
    string _value;

};
#endif
