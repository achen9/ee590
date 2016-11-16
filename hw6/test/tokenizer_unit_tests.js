// TOKENIZER FUNCTION TESTS
// This file tests the Tokenizer functions 
Tokenizer = require('./../tokenizer.js');
assert = require('assert');
t = new Tokenizer();
test_string = "-12. + 0.5 * (-1   + 2 / 3.0e+2 / -.9)"

t.add(/\d*\.?\d*(e|E)(-|\+)?\d+/) // Parse scientific notation
 .add(/\d+\.\d*/)                // Parse floating points
 .add(/\d*\.\d+/)                // Parse floating points
 .add(/\d+/)                     // Parse integers
 .add(/\+|-|\*|\/|%|\(|\)/)      // Parse arithmetic operators and parenthesis
 .add(/\s+/)                     // Parse whitespaces
 .tokenize(test_string);

// Test 1: Test current() function
assert('-' == t.current());

// Test 2: Test eat() function
t.eat();
t.eat();
assert('+' == t.eat());

// Test 3: Test eof() function
assert(false == t.eof());
for (var i = t.current_token_pos; i < t.tokens.length; i++) {
  t.eat();
}
assert(true == t.eof());

// Test 4: Test TokenizerException() function
try {
  t.eat();
} catch (e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
try {
  console.log('Trying to tokenize "-12.e + 0.5"')
  t.tokenize("-12.e + 0.5");
} catch (e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
try {
  console.log('Trying to tokenize "13.4 . / 2.3"')
  t.tokenize("13.4 . / 2.3");
} catch(e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
