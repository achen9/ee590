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
assert('+' == t.eat());

// Test 3: Test eof() function
assert(false == t.eof());
for (var i = t.current_token_pos; i < t.tokens.length - 1; i++) {
  t.eat();
}
assert(true == t.eof());

// Test 4: Test TokenizerException() function
try {
  t.eat()
} catch (e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
try {
  test_string = "-12.e + 0.5";
  t.tokenize(test_string);
} catch (e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
