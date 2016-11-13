function Tokenizer(regexps) {

  this.re_string = "";
  this.re;
  this.tokens = [];
  this.current_token_pos = 0;

  if ( regexps ) {
    for ( var i=0; i<regexps.length; i++ ) {
      this.add(regexps[i]);
    }
  }

}

Tokenizer.prototype.add = function(regexp) {
  if ( this.re_string == "" ) {
    this.re_string = regexp.source;
  } else {
    this.re_string += "|" + regexp.source;
  }
  this.re = RegExp(this.re_string,"g");
  return this;
}

Tokenizer.prototype.tokenize = function(str) {
  this.tokens = str.match(this.re);
  return this;
}

Tokenizer.prototype.current = function () {
  if (this.eof()) {
    return "No more tokens."
  } else {
    return this.tokens[this.current_token_pos];
  }
}

Tokenizer.prototype.float_val = function() {
  // Possibly useful to return the current value as a float
  // or return NaN if it doesn't evaluate (using the built in
  // method parseFloat)
  return parseFloat(this.current());
}

Tokenizer.prototype.next = function() {
  // TODO
}

Tokenizer.prototype.eat = function () {
  if (this.eof()) {
    return "No more tokens."
  } else {
    return this.tokens[this.current_token_pos++];
  }
}

Tokenizer.prototype.eof = function() {
  if (this.current_token_pos >= this.tokens.length) {
    return true;
  } else {
    return false;
  }
}

module.exports = Tokenizer;
