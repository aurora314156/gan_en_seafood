#ifndef NUMBER_H
#define NUMBER_H


#include <string>
#include "term.h"

using namespace std;

class Number: public Term{

public:
 
  Number(double s);
    
  string symbol()const;
  string value() const;

  string _symbol;
  string _value;
  
};

#endif
