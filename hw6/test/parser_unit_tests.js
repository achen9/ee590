// PARSER FUNCTION TESTS
// This file tests the Parser functions 
Parser = require('./../parser.js');
assert = require('assert');

// Test 1: Test factor() function
p1 = new Parser("12e3");
assert(12e3 == p1.factor(0));
console.log("Passed test 1");

// Test 2: Test term() function
p2 = new Parser("5 % 4 * 2.5 * 4 /2");
assert(5 == p2.term(0, 1));
console.log("Passed test 2");

// Test 3: Test expr() function
p3 = new Parser("2.4-5+4");
debugger;
assert(1.4 == p3.expr(0));
console.log("Passed test 3");

// Test 4: Test all functions in parser together
test_str = "-12. + 0.5 * (-1   + 2 / 3.0e+2 / -.9)";
p = new Parser(test_str);
console.log(test_str + " evaluates to " + p.parse());
