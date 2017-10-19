#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <string>
#include "term.h"
#include "atom.h"


class Struct: public Term{

public:
  
  Struct(Atom const & name, std::vector<Term *> args);

  Term * args(int index) {
    return _args[index];
  }
  Atom const & name() {
    return _name;
  }
  bool match(Term &term){
    Struct * ps = dynamic_cast<Struct *>(&term);
    if (ps){
      if (!_name.match(ps->_name))
        return false;
      if(_args.size()!= ps->_args.size())
        return false;
      for(int i=0;i<_args.size();i++){
        if(_args[i]->symbol() != ps->_args[i]->symbol())
            return false;
      }
      return true;
    }
    return false;
  }
  string symbol()const;
  string value()const;
  
  private:
    Atom _name;
    std::vector<Term *> _args;
};

#endif
