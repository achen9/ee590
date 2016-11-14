//
// Usage:
//   node test_parser.js "1.0 + 5.4/2"
//

Parser = require('./parser.js')
//test_str = "-12. + 0.5 * (-1   + 2 / 3.0e+2 / -.9)"
test_str = "1.0 + 5.4/2"
p = new Parser(test_str)
/*for (var i = 0; i < p.tokenizer.tokens.length; i++) {
  console.log(p.tokenizer.tokens[i]);
}*/
console.log(test_str + " evaluates to " + p.parse());
