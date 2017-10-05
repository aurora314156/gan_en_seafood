#ifndef UTTERM_H
#define UTTERM_H

#include "number.h"
#include "variable.h"
#include "atom.h"
#include <iostream>

//test Number.value()
TEST (Number,ctor){
    Number number(25);
    ASSERT_EQ("25",number.value());
    
}
//test Number.symbol()
TEST (Number, symbol) {
    Number number(25);
    ASSERT_EQ("number",number.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
   Number number1(25);
   Number number2(25);
   EXPECT_TRUE(number1.match(number2));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
  Number number1(25);
  Number number2(0);
  EXPECT_FALSE(number1.match(number2));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
    Number number(25);
    Atom tom("tom");
    EXPECT_FALSE(number.match(tom));
    
}
//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
    Atom tom("tom");
    Number number(25);
    EXPECT_FALSE(tom.match(number));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
   Number number(25);
   Variable X("X");
   EXPECT_TRUE(number.match(X));
  
}


// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
  
    Atom tom("tom");
    Variable X("X");
    
    EXPECT_TRUE(tom.match(X));
}

// ?- X=tom, tom=X.
// true
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
  
    Atom tom("tom");
    Variable X("X");
   
    EXPECT_TRUE(X.match(tom));
    EXPECT_TRUE(tom.match(X));
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
    Atom tom1("jerry");
    Atom tom2("tom");
    Variable X("X");
    
    EXPECT_TRUE(X.match(tom1));
    EXPECT_FALSE(X.match(tom2));
}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
   Number number(5);
   Variable X("X");
   X.match(number);
   EXPECT_TRUE(X.match(number));
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {
   Number number1(25);
   Number number2(100);
   Variable X("X");
   EXPECT_TRUE(X.match(number1));
   EXPECT_FALSE(X.match(number2));
}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {
   Number number(25);
   Variable X("X");
   Atom tom("tom");
   EXPECT_TRUE(X.match(tom));
   EXPECT_FALSE(X.match(number));
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {
   Atom tom("tom");
   Number number(25);
   Variable X("X");
   
   EXPECT_TRUE(tom.match(X));
   EXPECT_FALSE(number.match(X));
   
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){
    Atom tom("tom");
    Variable X("X");
    EXPECT_TRUE(X.match(tom));
    EXPECT_TRUE(X.match(tom));
}
#endif
