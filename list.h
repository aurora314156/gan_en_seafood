#ifndef LIST_H
#define LIST_H

#include "atom.h"
#include "variable.h"
#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>
using namespace std;



class List : public Term {
public:
  string symbol() const ;
  string value() const ;
  bool match(Term & term) {}
  bool match(List &list){
    if (this == &list)
    {
      return true;
    }
    else
    {
      if (this->size() == list.size())
      {
        for (int i = 0; i < list.size(); i++)
        {
          if (_elements[i]->isNumber == true && list._elements[i]->isVariable == true)
          {
            
            return true;
          }
          else if (_elements[i]->match(*list._elements[i]) == false)
          {
            return false;
          }
        }
        return true;
      }
      else
      {
        return false;
      }
    }
  }
  bool match(Variable &var){
    for (int i = 0; i < this->arity(); i++)
    {
      if (this->count(i).symbol() == var.symbol())
      {
        return false;
      }
    }
  
    if (!var._inst)
    {
      var._inst = this;
      return true;
    }
    return var._inst->match(*this);
  }
public:
  List (): _elements() {isList=true;}
  List (vector<Term *> const & elements):_elements(elements){isList=true;}
  Term * head() const;
  List * tail() const;
 /* Term * args(int index) {
    return _elements[index];
  }*/
  Term count (int &j)
  {
    return * _elements[j];
  }
  int arity() {return _elements.size();}

  
private:
  vector<Term *> _elements;
  
};

#endif
