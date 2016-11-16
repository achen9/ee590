Tokenizer = require('./tokenizer.js')

function Parser(str) {

  this.str = str; // the string to be parsed
  this.tokenizer = new Tokenizer();
  this.tokenizer
   .add(/\d*\.?\d*(e|E)(-|\+)?\d+/) // Parse scientific notation
   .add(/\d+\.\d*/)                 // Parse floating points
   .add(/\d*\.\d+/)                 // Parse floating points
   .add(/\d+/)                      // Parse integers
   .add(/\+|-|\*|\/|%|\(|\)/)       // Parse arithmetic operators and parenthesis
   .add(/\s+/)                      // Parse whitespaces
  this.tokenizer.tokenize(str);
}

Parser.prototype.factor = function(stack) {
  this.tokenizer.eat_whitespace();
  var pf = this.tokenizer.float_val();
  if(!isNaN(pf)) {
    this.tokenizer.eat();
    if((!isNaN(this.tokenizer.float_val()) || '(' === this.tokenizer.current()) && !this.tokenizer.eof()) {
      this.parseException();
    }
    return pf;
  } else if('(' === this.tokenizer.current()) {
    this.tokenizer.eat();
    this.tokenizer.eat_whitespace();
    pf = this.expr(stack + 1);
    this.tokenizer.eat_whitespace();
    if(')' === this.tokenizer.current()) {
      this.tokenizer.eat();
      if(!isNaN(this.tokenizer.current()) && !this.tokenizer.eof()) {
        this.parseException();
      }
    } else if(this.tokenizer.eof()) {
      throw new ParserException("Unexpected EOF", this.str.length);
    } else {
      this.parseException();
    }
    return pf;
  } else if('-' === this.tokenizer.current() || '+' === this.tokenizer.current()) {
    pf = this.expr();
    return pf;
  } else {
    this.parseException();
  }
}

Parser.prototype.term = function(stack, sign) {
  var f;
  var number;
  this.tokenizer.eat_whitespace();
  number = this.factor(stack) * sign;
  this.tokenizer.eat_whitespace();
  
  while('*' === this.tokenizer.current() || '/' === this.tokenizer.current() || '%' === this.tokenizer.current()) {
    var operator = this.tokenizer.current();
    this.tokenizer.eat();
    this.tokenizer.eat_whitespace();
    f = this.factor(stack);
    this.tokenizer.eat_whitespace();
    if('*' === operator) {
      number *= f;
    } else if ('/' === operator) {
      number /= f;
    } else {
      number %= f;
    }
  }
  return number;
}

Parser.prototype.expr = function(stack) {
  var t;
  var number;
  var sign = 1;
  this.tokenizer.eat_whitespace();
  while('-' === this.tokenizer.current() || '+' === this.tokenizer.current()) {
    var op = this.tokenizer.current();
    this.tokenizer.eat();
    this.tokenizer.eat_whitespace();
    if ('-' === op) {
      sign *= -1;
    }
  }
  number = this.term(stack, sign);
  this.tokenizer.eat_whitespace();
  while('-' === this.tokenizer.current() | '+' === this.tokenizer.current()) {
    var operator = this.tokenizer.current();
    this.tokenizer.eat();
    this.tokenizer.eat_whitespace();
    if('-' === operator) {
      t = this.term(stack, -1);
    } else {
      t = this.term(stack, 1);
    }
    number += t;
  }
  if(0 === stack && ')' === this.tokenizer.current() && !this.tokenizer.eof()) {
    this.parseException();
  }
  return number;
}

Parser.prototype.parse = function() {
  return this.expr(0);
}

Parser.prototype.parseException = function () {
  var pos = 0;
  for (var i = 0; i < this.tokenizer.current_token_pos; i++) {
    pos += this.tokenizer.tokens[i].length;
  }
  throw new ParserException("Unexpected token '" + this.tokenizer.current() + "'", pos + 1);
}

function ParserException(errmsg, errpos) {
  this.name = "ParserException";
  this.msg = errmsg;
  this.position = errpos;
}

module.exports = Parser, ParserException;
