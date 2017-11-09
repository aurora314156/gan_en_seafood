#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "atom.h"
using std::string;

#include "global.h"
#include "scanner.h"


class Parser{
public:
  Parser(Scanner scanner);
  Term* createTerm();
  vector<Term*> getArgs();
private:
  Scanner _scanner;
  int _currentToken;
};
#endif