Tokenizer = require('./tokenizer.js')

function Parser(str) {

  this.str = str; // the string to be parsed
  this.tokenizer = new Tokenizer();
  this.tokenizer
   .add(/((-|\+)?)\d*.\d*(e|E)((-|\+)?)\d+/) // Parse scientific notation
   .add(/(-?)\d*\.\d*/)                      // Parse  floating points
   .add(/-?\d+/)                             // Parse integers
   .add(/\+|-|\*|\/|%|\(|\)/)                // Parse arithmetic operators and parenthesis
   .add(/\s*/)                               // Parse whitespaces
  this.tokenizer.tokenize(str);
}

Parser.prototype.factor = function () {
  this.tokenizer.eat_whitespace();
  var pf = this.tokenizer.float_val();
  if(!isNaN(pf)) {
    this.tokenizer.eat();
    return pf;
  } else if('(' == this.tokenizer.current()) {
    this.tokenizer.eat();
    this.tokenizer.eat_whitespace();
    pf = this.expr();
    this.tokenizer.eat_whitespace();
    if (')' == this.tokenizer.current()) {
      this.tokenizer.eat();
    } else {
      throw new ParserException("Incorrect token " + this.tokenizer.current(), this.tokenizer.current_token_pos);
    }    
    return pf;
  }
}

Parser.prototype.term = function() {
  var f;
  var number;
  this.tokenizer.eat_whitespace();
  number = this.factor();
  debugger;
  this.tokenizer.eat_whitespace();
  while('*' == this.tokenizer.current() | '/' == this.tokenizer.current() | '%' == this.tokenizer.current()) {
    var operator = this.tokenizer.eat();
    this.tokenizer.eat_whitespace();
    f = this.factor();
    this.tokenizer.eat_whitespace();
    if('*' == operator) {
      number *= f;
    } else if ('/' == operator) {
      number /= f;
    } else {
      number %= f;
    }
  }
  return number;
}

Parser.prototype.expr = function() {
  var t;
  var number;
  this.tokenizer.eat_whitespace();
  number = this.term();
  this.tokenizer.eat_whitespace();
  while('-' == this.tokenizer.current() | '+' == this.tokenizer.current()) {
    var operator = this.tokenizer.eat();
    this.tokenizer.eat_whitespace();
    t = this.term();
    this.tokenizer.eat_whitespace();
    if('-' == operator) {
      number -= t;
    } else {
      number += t;
    }
  }
  return number;
}

Parser.prototype.parse = function() {
  return this.expr();
}

function ParserException(errmsg, errpos) {
  this.name = "ParserException";
  this.msg = errmsg;
  this.position = errpos;
}

module.exports = Parser, ParserException;
