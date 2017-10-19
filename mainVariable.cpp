#include "number.h"
#include "atom.h"
#include "variable.h"
#include "struct.h"


bool Variable::match(Term &term){

	Struct* s = dynamic_cast <Struct*> (&term);
    Variable* v = dynamic_cast <Variable*> (&term);
	
	if(_symbol==term.symbol()) 
		return true; 

	if (_sign || _value == term.symbol()){

        // match to variable
		if (v!=NULL){
            // not match yet 
            if (v->_sign){ 
				v->vec.push_back (this);
				vec.push_back (v);
				_value = v->value();
				
				if (vec.size()!=0) { 
					for (int i = 0 ; i < vec.size() ; i++)
						v->vec.push_back (vec[i]);
				}
				if (v->vec.size()!=0){ 
					for (int j = 0 ; j < v->vec.size() ; j++)
						vec.push_back(v->vec[j]);
				}
            }
            // when already match
			else{ 
				_sign = false;
				_value = v->value();
			}
			return true;
		}
		// match to struct
		if (s!=NULL){
            
			str = s;
			return true;
		}
		
        // match different things
        // and assign to other match variable
		_value = term.symbol();

		if (vec.size()!=0) {

			for (int i = 0 ; i < vec.size() ; i++)
				vec[i]->_value = term.symbol();
		}
		_sign = false;	
		return true;
	}
	return false;
}


//x=y,x=tom
//y=tom