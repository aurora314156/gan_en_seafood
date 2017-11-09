#include <string>
#include <vector>

#include "atom.h"
#include "variable.h"
#include "struct.h"
#include "global.h"
#include "scanner.h"
#include "parser.h"
#include "list.h"
using std::string;


Parser::Parser(Scanner scanner) : _scanner(scanner){}

  Term* Parser::createTerm(){

    int token = _scanner.nextToken();
   // _scanner.skipLeadingWhiteSpace();
    
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token==ATOMSC ){
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '(' ) {
          _scanner.nextToken() ;
        
          if(_scanner.currentChar() == ')'){
            _scanner.nextToken();
            return new Struct(*atom);
          }
          
          vector<Term*> terms = getArgs();
          if(_currentToken == ')')
            return new Struct(*atom, terms);
        }
        else{
          return atom;
        }
    }
   
    else if(token == '['){
      _scanner.skipLeadingWhiteSpace();
      if(_scanner.currentChar() == ']')
      {
        _scanner.nextToken();
        
        return new List();
      }
      
      std::vector<Term *>terms = getArgs();

      if(_currentToken == ']')
      {
        return new List(terms);
      }
      else{
        throw string("unexpected token");
      }
      
    }
    
    return nullptr;
  }

  vector<Term*> Parser::getArgs()
  {
    Term* term = createTerm();
    vector<Term*> args;
    if(term)
      args.push_back(term);
    while((_currentToken = _scanner.nextToken()) == ',') {
      args.push_back(createTerm());
    }
    return args;
  }