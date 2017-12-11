#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include "struct.h"
#include "list.h"
#include <queue>
#include <stack>
#include <vector>

template <class T>
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual T currentItem() const = 0;
  virtual bool isDone() const = 0;
};

class BFSIterator :public Iterator<Term*>{
public:
  BFSIterator(Term *n):_n(n){}

  void first(){
    Iterator<Term*> *it = _n->createIterator();
    for(it->first();!(it->isDone()); it->next()){
      Tempqueue.push(it->currentItem());
      Bfsqueue.push(it->currentItem());
    }
    while(Tempqueue.size()!=0){
      Iterator<Term*> *Tempiter =  Tempqueue.front()->createIterator();
      Tempqueue.pop();
      if(!(Tempiter->isDone())){
        for(Tempiter->first();!(Tempiter->isDone()); Tempiter->next()){
          Tempqueue.push(Tempiter->currentItem());
          Bfsqueue.push(Tempiter->currentItem());
        }
      }
    }
  }

  void next(){
    Bfsqueue.pop();
  }

  Term * currentItem() const{
    return Bfsqueue.front();
  }

  bool isDone() const{
    return Bfsqueue.empty();
  }

  private:
  std::queue<Term *> Bfsqueue;
  std::queue<Term *> Tempqueue;
  int _index;
  Term* _n;
};

class DFSIterator :public Iterator<Term*>{
public:
  DFSIterator(Term *n):_n(n){}

  void first(){
    Iterator<Term*> *it = _n->createIterator();
    for(it->first();!(it->isDone()); it->next()){
      Tempvector.push_back(it->currentItem());
    }
    while(Tempvector.size()!=0){
     
      Tempstack.push(Tempvector.back());
      Tempvector.pop_back();
    }
    while(Tempstack.size()!=0){
      Iterator<Term*> *Tempiter = Tempstack.top()->createIterator();
      Term* _term = Tempstack.top();
        if(!(Tempiter->isDone())){
          Tempstack.pop();
          for(Tempiter->first();!(Tempiter->isDone()); Tempiter->next()){
            Tempvector.push_back(Tempiter->currentItem());
          }
          while(Tempvector.size()!=0){
            Tempstack.push(Tempvector.back());
            Tempvector.pop_back();
          }
          Dfsqueue.push(_term);
        }else{
          Tempstack.pop();
          Dfsqueue.push(_term);
        }
    }
  }

  void next(){
    Dfsqueue.pop();
  }

  Term * currentItem() const{
    return Dfsqueue.front();
  }

  bool isDone() const{
    return Dfsqueue.empty();
  }

private:
  std::queue<Term *> Dfsqueue;
  std::stack<Term *> Tempstack;
  std::vector<Term *> Tempvector;
  Term* _n;
};


class NullIterator :public Iterator<Term*>{
public:
  NullIterator(Term *n){}
  void first(){}
  void next(){}
  Term * currentItem() const{
      return nullptr;
  }
  bool isDone() const{
    return true;
  }

};

class StructIterator :public Iterator<Term*> {
public:
  StructIterator(Struct *s): _index(0), _s(s) {}

  
  Term* currentItem() const {
    return _s->args(_index);
  }

  bool isDone() const {
    return _index >= _s->arity();
  }
  void first() {
    _index = 0;
  }
  void next() {
    _index++;
  }
private:
  int _index;
  Struct* _s;
};

class ListIterator :public Iterator<Term*> {
public:
  ListIterator(List *list): _index(0), _list(list) {}

  Term* currentItem() const {
    return _list->args(_index);
  }

  bool isDone() const {
    return _index >= _list->arity();
  }
  void first() {
    _index = 0;
  }
  void next() {
    _index++;
  }
private:
  int _index;
  List* _list;
};
#endif
