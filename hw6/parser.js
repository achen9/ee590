Tokenizer = require('./tokenizer.js')

function Parser(str) {

  this.str = str; // the string to be parsed
  this.tokenizer = new Tokenizer();
  this.tokenizer
   .add(/\d*.\d*(e|E)((-|\+)?)\d+/) // Parse scientific notation
   .add(/\d*\.\d*/)                 // Parse  floating points
   .add(/\d+/)                      // Parse integers
   .add(/\+|-|\*|\/|%|\(|\)/)       // Parse arithmetic operators and parenthesis
   .add(/\s*/)                      // Parse whitespaces
  this.tokenizer.tokenize(str);
}

Parser.prototype.factor = function () {
  this.tokenizer.eat_whitespace();
  var pf = this.tokenizer.float_val();
  if (!isNaN(pf)) {
    if (!this.tokenizer.eof()) {
      this.tokenizer.eat();
    }
    return pf;
  } else if('(' == this.tokenizer.current()) {
    this.tokenizer.eat();
    this.tokenizer.eat_whitespace();
    pf = this.expr();
    this.tokenizer.eat_whitespace();
    if (')' == this.tokenizer.current()) {
      if (!this.tokenizer.eof()) {
        this.tokenizer.eat();
      }
    } else {
      var pos = 0;
      for (var i = 0; i < this.tokenizer.current_token_pos; i++) {
        pos += this.tokenizer.tokens[i].length;
      }
      throw new ParserException("Unexpected token '" + this.tokenizer.current() + "'", pos + 1);
    }
    return pf;
  } else if ('-' == this.tokenizer.current() | '+' == this.tokenizer.current()) {
    pf = this.expr();
    return pf;
  } else {
    var pos = 0;
    for (var i = 0; i < this.tokenizer.current_token_pos; i++) {
      pos += this.tokenizer.tokens[i].length;
    }
    throw new ParserException("Unexpected token '" + this.tokenizer.current() + "'", pos + 1);
  }
}

Parser.prototype.term = function(sign) {
  var f;
  var number;
  this.tokenizer.eat_whitespace();
  number = this.factor() * sign;
  this.tokenizer.eat_whitespace();
  
  while ('*' == this.tokenizer.current() | '/' == this.tokenizer.current() | '%' == this.tokenizer.current()) {
    var operator = this.tokenizer.current();
    this.tokenizer.eat();
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
  var sign = 1;
  this.tokenizer.eat_whitespace();
  while ('-' == this.tokenizer.current() | '+' == this.tokenizer.current()) {
    var op = this.tokenizer.current();
    this.tokenizer.eat();
    this.tokenizer.eat_whitespace();
    if ('-' == op) {
      sign *= -1;
    }
  }
  number = this.term(sign);
  this.tokenizer.eat_whitespace();
  while('-' == this.tokenizer.current() | '+' == this.tokenizer.current()) {
    var operator = this.tokenizer.current();
    this.tokenizer.eat();
    this.tokenizer.eat_whitespace();
    if('-' == operator) {
      t = this.term(-1);
    } else {
      t = this.term(1);
    }
    number += t;
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
