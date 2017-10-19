#include "struct.h"

Struct::Struct(Atom const & name, std::vector<Term *> args): _name(name), _args(args) {}

string Struct::symbol () const{

    string temp = _name.symbol() + "(";
    for(int i = 0; i < _args.size() - 1 ; i++){
      temp += _args[i]-> symbol() + ", ";
    }
    temp += _args[_args.size()-1]-> symbol() + ")";
    return  temp;

}
string Struct::value () const{
    
        string temp =_name.symbol() + "(";
        for(int i = 0; i < _args.size() - 1 ; i++){
          temp += _args[i]-> value() + ", ";
        }
        temp += _args[_args.size()-1]-> value() + ")";
        return  temp;
    
}

