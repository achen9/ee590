Tokenizer = require('./tokenizer.js')

function Parser(str) {

  this.str = str; // the string to be parsed

  this.tokenizer = new Tokenizer();

  this.tokenizer
      .add(/(-?)\d*.\d*e(-?)\d+/) // Parse scientific notation
      .add(/(-?)\d*\.\d*/)        // Parse  floating points
      .add(/-?\d+/)               // Parse integers
      .add(/\+|-|\*|\/|%|\(|\)/)  // Parse arithmetic operators and parenthesis

}

Parser.prototype.factor = function() {
  // TODO
}

Parser.prototype.term = function() {
  // TODO
}

Parser.prototype.exr = function() {
  // TODO
}

Parser.prototype.parse = function() {
  // TODO
}

module.exports = Parser;
