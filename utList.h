#ifndef UTLIST_H
#define UTLIST_H

#include <string>
#include "list.h"
#include "struct.h"
#include "atom.h"
#include "variable.h"


using namespace std;

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST (List, constructor) {
  List list;
  EXPECT_EQ("[]",list.symbol());
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers) {
  Number num1(496);
  Number num2(8128);
  vector<Term *> vc = {&num1,&num2};
  List list(vc);
  EXPECT_EQ("[496, 8128]",list.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms) {
  Atom t("terence_tao");
  Atom a("alan_mathison_turing");
  vector<Term *> vc = {&t, &a};
  List L(vc);
  EXPECT_EQ("[terence_tao, alan_mathison_turing]",L.symbol());
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars) {
  Variable X("X");
  Variable Y("Y");
  vector<Term *>vc ={&X,&Y};
  List L(vc);
  EXPECT_EQ("[X, Y]",L.symbol());
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail) {
  Number num(496);
  Variable X("X");
  Atom t("terence_tao");
  vector<Term *> vc = {&num,&X,&t};
  List L(vc);
  Atom tom("tom");
  EXPECT_FALSE(tom.match(L));
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail) {
  Number num (496);
  Variable X("X");
  Atom t("terence_tao");
  vector<Term *> vc = {&num,&X,&t};
  Number num2(8128);
  List list(vc);
  EXPECT_FALSE(num2.match(list));
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail) {
  Variable X("X");
  vector<Term *> v = {&X};
  Struct s(Atom("s"), v);
  Number num(496);
  Number num2(8128);
  Atom t("terence_tao");
  vector<Term *> vc = {&num ,&X, &t};
  List List(vc);

  EXPECT_FALSE(s.match(List));
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed) {
  Number num(496);
  Variable X("X");
  Atom t("terence_tao");
  vector<Term *> vc = {&num,&X,&t};
  List L(vc);
  Variable Y("Y");
  EXPECT_TRUE(Y.match(L));
}

// ?- X = [496, X, terence_tao].
// false.
TEST(List, matchToVarOccuredInListShouldFail) {
  Number num(496);
  Variable X("X");
  Atom t("terence_tao");
  vector<Term *> vc = {&num,&X,&t};
  List L(vc);
  EXPECT_TRUE(X.match(L));
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed) {
  Variable X("X");
  Number num (496);
  Atom t("terence_tao");
  vector<Term *> vc = {&num,&X,&t};
  List list (vc);
  List list2 (vc);
  EXPECT_TRUE(list.match(list2));
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed) {
  Variable X("X");
  Variable Y("Y");
  Number num (496);
  Atom t("terence_tao");
  vector<Term *> vc = {&num,&X,&t};
  vector<Term *> vc1 = {&num,&Y,&t};
  List list (vc);
  List list2 (vc1);
  EXPECT_TRUE(list.match(list2));
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed) {
  Variable X("X");
  Number num (496);
  Number num2(8128);
  Atom t("terence_tao");
  vector<Term *> vc = {&num,&X,&t};
  vector<Term *> vc1 = {&num,&num2,&t};
  List list (vc);
  List list2 (vc1);
  EXPECT_TRUE(list.match(list2));
  EXPECT_TRUE(X.match(num2));
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed) {
  Number num1(496);
  Variable X("X");
  Variable Y("Y");
  Atom atom1("terence_tao");
  Atom atom2("alan_mathison_turing");
  X.match(atom2);
  vector<Term *> v1 = {&num1, &X, &atom1};
  List list1(v1);
  Y.match(list1);
  EXPECT_EQ("[496, alan_mathison_turing, terence_tao]",Y.value());
  EXPECT_EQ("alan_mathison_turing",X.value());
}

// Example: 
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1) {
Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ("first", l.head()->symbol());
  EXPECT_EQ("[second, third]", l.tail()->value());
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("second"), l.tail()->head()->value());
  EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> vc = {&f};
  List list(vc);
  vector<Term *> vc1 = {&list, &s, &t};
  List list1(vc1);
  EXPECT_EQ(string("second"), list1.tail()->head()->value());
  EXPECT_EQ(string("[third]"), list1.tail()->tail()->value());
}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> vc = {&f, &s, &t};
  List l(vc);
  EXPECT_EQ(string("third"), l.tail()->tail()->head()->value());
  EXPECT_EQ(string("[]"), l.tail()->tail()->tail()->value());
}
 
// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST (List, emptyExecptionOfHead) {
  List list;
  try{
     list.head()->value();
  }catch(string const & error) {
     EXPECT_EQ("Accessing head in an empty list",error);
  }
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST (List, emptyExecptionOfTail) {
  List list;
  try{
     list.tail()->value();
  }catch(string const & error) {
     EXPECT_EQ("Accessing tail in an empty list",error);
  }
}


#endif
