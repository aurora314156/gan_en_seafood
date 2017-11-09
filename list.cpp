#include "list.h"
#include "variable.h"
#include <typeinfo>

#include <vector>

string List::symbol() const {
    string ret ="[";
    
    if(_elements.size() != 0){

        int i = 0;

      for(; i < _elements.size() - 1 ; ++i)
        ret += _elements[i]-> symbol() + ", ";
      ret += _elements[i]-> symbol();
    }
    ret += "]";
    return  ret;
 }
Term * List:: head() const{
    if (!_elements.empty()){;
        return _elements[0] ;
      }else{
          throw string("Accessing head in an empty list");
      }

}
List *List:: tail() const{

    vector<Term *> tail;
    if (!_elements.empty()){
        for(int i =1; i<_elements.size();i++){
            tail.push_back(_elements[i]);
        }
        return new List(tail);
    }else{
        throw string("Accessing tail in an empty list");
      
    }
};
bool List::match(Term & term){
  bool ret = false;

  if(typeid(term) == typeid(Variable)){
    ret = term.match(*this);
  }
  else if(_elements.size() != 0){

    List *pt = dynamic_cast<List *>(&term);
    
    if(pt!=NULL){
      ret = compare(pt);
    }

  }
  return ret;
}
bool List::compare(List *list){

  if(_elements.size() != list->_elements.size()) 
    return false;
  for(int i = 0; i < _elements.size(); i++)
    if(!(_elements[i]->match(*(list->_elements[i])))) 
      return false;
  
  return true;
}