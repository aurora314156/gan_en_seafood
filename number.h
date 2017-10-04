#ifndef NUMBER_H
#define NUMBER_H


#include <string>
#include "atom.h"
#include "variable.h"


using namespace std;

class Atom;
class Variable;

class Number{
public:
 
  Number(int s){
    num = s;
    symbol = to_string(s);
  }
  string value;
  bool assignable = true;

  bool operator ==(Number number) {return num == number.num;}

  bool match(Atom atom);
  bool match(Variable &v);

  int getnumber(){return num;}
  string getsymbol(){return symbol;}


  string symbol;
  int num;
  
};

#endif
