#ifndef LIST_H
#define LIST_H

#include "atom.h"

#include <vector>
#include <string>
using std::vector;

class List : public Term {
public:
  string symbol() const;
  string value() const{return symbol();}
  bool match(Term & term);
  List (): _elements() {}
  List (vector<Term *> const & elements):_elements(elements){}
  Term * head() const;
  List * tail() const;
  bool compare(List *list);
private:
  vector<Term *> _elements;

};

#endif
