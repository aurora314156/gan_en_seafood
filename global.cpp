#include "global.h"
#include <algorithm>

using namespace std;

vector<pair<string, int>> symtable;

bool isSpecialCh(char c) {
    return c == '+'
        // || c == '=' // ... the matching operator
           || c == '-'
           || c == '*'
           || c == '/'
           || c == '<'
           || c == '>'
           || c == '.'
           || c == '&'
           || c == '\\'
           || c == '~'
           || c == '^'
           || c == '$'
           || c == '#'
           || c == '@'
           || c == '?'
           || c == ':';
  }
  
 bool symbolExist(string s, int & val) {
    bool found = false;
    val = -1;
    auto it = find_if(symtable.begin(), symtable.end(), [s](pair<string, int> ele) {
      return ele.first == s;
    });
  
    found = symtable.end() != it;
    if (found)
     val = it - symtable.begin();
  
    return found;
  }