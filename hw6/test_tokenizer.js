// TOKENIZER FUNCTION TESTS
// This file tests the Tokenizer functions 
Tokenizer = require('./tokenizer.js');
assert = require('assert');
t = new Tokenizer();
test_string = "-12. + 0.5 * (-1   + 2 / 3.0e+2 / -.9)"

t.add(/((-|\+)?)\d*.\d*(e|E)((-|\+)?)\d+/) // Parse scientific notation
 .add(/(-?)\d*\.\d*/)                      // Parse  floating points
 .add(/-?\d+/)                             // Parse integers
 .add(/\+|-|\*|\/|%|\(|\)/)                // Parse arithmetic operators and parenthesis
 .add(/\s*/)                               // Parse whitespaces
 .tokenize(test_string);

// Test 1: Test current() function
assert(-12 == parseFloat(t.current()));

// Test 2: Test eat() function
t.eat();
t.eat();
assert('+' == t.current());

// Test 3: eof() function

