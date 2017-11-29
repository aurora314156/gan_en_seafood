#include "atom.h"
#include "variable.h"
#include <typeinfo>
#include <iostream>
#include <string>
#include "list.h"
using std::vector;

string List::symbol() const{
    string ret ;
    if(_elements.size()==0 ){
      ret = "[]";
    }
    else{
      ret  = "[";
      std::vector<Term *>::const_iterator it = _elements.begin();
      for( ; it != _elements.end()-1 ; ++it ){
        ret += (*it)->symbol()+", ";
      }
      ret += (*it)->symbol()+"]";
    }
    return ret;
  }
string List::value() const{
    string ret ;
    if(_elements.empty()){
        ret = "[]";
    }
    else{
        ret  = "[";
        std::vector<Term *>::const_iterator it = _elements.begin();
        for( ; it != _elements.end()-1 ; ++it ){
        ret += (*it)->value()+", ";
        }
        ret += (*it)->value()+"]";
}
return ret;
}






Term * List::head() const{
    if(_elements.empty())
        throw std::string("Accessing head in an empty list");

    return _elements[0];
}
List * List::tail() const {
    if(_elements.empty())
        throw std::string("Accessing tail in an empty list");
    vector<Term *> _clone_elements;
    _clone_elements.assign(_elements.begin()+1, _elements.end());
    List *ls= new List(_clone_elements) ;
    return ls;
}
