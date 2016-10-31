#include <iostream>
#include "json.hh"
#include "test.hh"

int main ( int argc, char * argv[] ) {
  // EXAMPLE JSON TESTS
  // This file tests the construction of an example JSON
  // data structure

  // Test 1: Check JSON data structure can be created
  // First hash key
  Hash h;
  String s1("is fun");
  h.set("ee590", s1);
  // Second hash key
  Array a1;
  String s2("is");
  a1.set(0, s2);
  Hash h1;
  String s3("arcane");
  h1.set("adjective", s3);
  a1.set(1, h1);
  h.set("C++", a1);
  // Third hash key
  Hash h2;
  String s4("hipsters");
  h2.set("used by", s4);
  Boolean b1(true);
  h2.set("poetic", b1);
  h.set("Ruby", h2);
  // Fourth hash key
  Array a2;
  String s5("JavaHomeworkAssignmentTestCodeLibraryAssessorFuncTest");
  a2.set(0, s5);
  Number n1(0);
  a2.set(1, n1);
  String s6("zero");
  a2.set(3, s6);
  Hash h3;
  a2.set(4, h3);
  h.set("Java", a2);
  // Fifth hash key
  String s7("Resistance is futile");
  h.set("Javascript", s7);

  std::cout << std::endl << h.stringify() << std::endl;

  // Test set 2: Spot check JSON data correctness
  ASSERT("arcane" == h.get("C++")->get(1)->get("adjective")->get_str());
  ASSERT(true == h.get("Ruby")->get("poetic")->get_bool());
  ASSERT("zero" == h.get("Java")->get(3)->get_str());
  ASSERT("Resistance is futile" == h.get("Javascript")->get_str());

  SUCCEED;
}
