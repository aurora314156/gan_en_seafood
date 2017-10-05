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
    num = to_string(s);
    sym = to_string(s);
  }
  

  
  bool match(Number n);
  bool match(Atom atom);
  bool match(Variable &v);

  string value(){return num;}
  string symbol(){return sym;}


  string sym;
  string num;
  
};

#endif
