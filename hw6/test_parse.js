// PARSER FUNCTION TESTS
// This file tests the Parser functions 
Parser = require('./parser.js');

// Test 1: Test parser using input from terminal
try {
  p = new Parser(process.argv[2]);
  console.log(process.argv[2] + " evaluates to " + p.parse());
} catch (e) {
  console.log(e.name + ": " + e.msg + " at position " + e.position);
}
