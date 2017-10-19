#include "number.h"
#include <string>
#include <iostream>

Number::Number(double s ){

    string num = to_string(s);
    string temp;
    int end = 0;

    for(end =num.size()-1;end>0;end--)
    if(num[end]!='0')break;

    for(int i =0;i<end+1;++i)
    temp+=num[i];
    
    _symbol = temp;
    _value = temp;
}

string Number::symbol() const{
    return _symbol;
}
string Number::value() const{
    return _value;
}