Tokenizer = require('./tokenizer.js');

t = new Tokenizer();

test_string = "e12+0.5*(-1+2/3.0e/-9)"

t.add(/(-?)\d*.\d*(e|E)(-?)\d*/) // Parse scientific notation
 .add(/(-?)\d*\.\d*/)            // Parse  floating points
 .add(/-?\d+/)                   // Parse integers
 .add(/\+|-|\*|\/|%|\(|\)/)      // Parse arithmetic operators and parenthesis
 .tokenize(test_string);

console.log(t.tokens);

// Test 1: current() function 
console.log(t.current());

// Test 2: eat() function
for (var i = 0; i < t.tokens.length; i++) {
  console.log(t.eat());
}
console.log(t.eat());
console.log(t.current());

// Test 3: eof() function
