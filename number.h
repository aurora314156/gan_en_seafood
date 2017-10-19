#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "term.h"

using namespace std;

class Number: public Term{

public:
 
  Number(double s);
    
  string symbol() const{
    return _symbol;
  }
  string value() const{
    return _value;
  }
  string _symbol;
  string _value;
  
  bool match (Term &term);

};

#endif
