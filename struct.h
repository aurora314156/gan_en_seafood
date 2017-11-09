#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include "struct.h"
#include <vector>
#include <string>

using std::string;

class Struct: public Term {
public:
  Struct(Atom const &name):_name(name),_args(){};

  Struct(Atom const &name, std::vector<Term *> args): _name(name) ,_args(args){};

  Term * args(int index) {
    return _args[index];
  }

  Atom & name() {
    return _name;
  }
  string symbol() const {
    string ret = _name.symbol() + "(";
    std::vector<Term *>::const_iterator it = _args.begin();
    for (; it != _args.end()-1; ++it)
      ret += (*it)->symbol()+", ";
    ret  += (*it)->symbol()+")";
    return ret;
  }
  string value() const {
    string ret = _name.symbol() + "(";
    std::vector<Term *>::const_iterator it = _args.begin();
    for (; it != _args.end()-1; ++it)
      ret += (*it)->value()+", ";
    ret  += (*it)->value()+")";
    return ret;
  }

  bool match(Term &term){

    Struct * ps = dynamic_cast<Struct *> (&term);
    if(ps)
    {
        if((!_name.match(ps->_name)) || (_args.size()!=ps->_args.size()))
            return false;
        for(int p=0;p<_args.size();p++)
        {
            if(ps->_args[p]->symbol() != _args[p]->symbol())
                return false;    
        }
        return true;
    }
    return false;
    
  }
  int arity()const{
    int sizeOfargs = 0;
    for(int s = 0;s<_args.size();s++)
      sizeOfargs++;
    return sizeOfargs;
  }
   
  
private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
