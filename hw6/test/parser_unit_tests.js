// PARSER FUNCTION TESTS
// This file tests the Parser functions 
Parser = require('./../parser.js');
assert = require('assert');

// Test 1: Test factor() function
p1 = new Parser("12e3");
assert(12e3 == p1.factor(0));

// Test 2: Test term() function
p2 = new Parser("5 % 4 * 2.5 * 4 /2");
assert(5 == p2.term(0, 1));

// Test 3: Test expr() function
p3 = new Parser("2.4-5+4");
assert(1.4 == p3.expr(0));

// Test 4: Test all functions in parser together
test_str = "-12. + 0.5 * (-1 -+-+ 2 / 3.0e+2 / -.9)";
p = new Parser(test_str);
console.log(test_str + " evaluates to " + p.parse());

// Test 5: Test ParserException() function
try {
  p4 = new Parser("((12%5)");
  console.log('Trying to parse "((12%5)"');
  p4.parse();
} catch(e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
try {
  p5 = new Parser(".3e+2*.2)");
  console.log('Trying to parse ".3e+2*.2)"');
  p5.parse();
} catch(e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
try {
  p6 = new Parser("13.5(12.6 + 6)");
  console.log('Trying to parse "13.5(12.6 + 6)"');
  p6.parse();
} catch(e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
try {
  p7 = new Parser("4.5 + (1.2 - 4)18e9");
  console.log('Trying to parse "4.5 + (1.2 - 4)18e9"');
  p7.parse();
} catch(e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
try {
  p8 = new Parser("4.5 + / 12.6");
  console.log('Trying to parse "4.5 + / 12.6"');
  p8.parse();
} catch(e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
try {
  p9 = new Parser("4.5 6.23e-2 + 9");
  console.log('Trying to parse "4.5 6.23e-2 + 9"');
  p9.parse();
} catch(e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
