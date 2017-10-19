#include "atom.h"

Atom :: Atom (string s) : _symbol (s),_value(s) {}

string Atom::symbol () const { return _symbol;}
string Atom::value () const { return _value;}