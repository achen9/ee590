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
  var tmp = [];
  var tmpstr;
  this.tokens = str.match(this.re);
  // Removes empty elements in array produced by match()
  for (var i = 0; i < this.tokens.length; i++) {
    if('' != this.tokens[i]) {
        tmp.push(this.tokens[i]);
    }
  }
  this.tokens = tmp;
  tmpstr = this.tokens.join('');
  for(var i = 0; i < str.length; i++) {
    if (str[i] !== tmpstr[i]) {
      throw new TokenizerException("Unexpected token '" + str[i] + "'", i + 1);
    }
  }
  return this;
}

Tokenizer.prototype.current = function () {
  if (this.eof()) {
    throw new TokenizerException("No more tokens.", this.tokens.length - 1);
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
/*
Tokenizer.prototype.next = function() {
  // TODO
}*/

Tokenizer.prototype.eat = function () {
  if (this.eof()) {
    throw new TokenizerException("No more tokens to eat.", this.tokens.length - 1);
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

Tokenizer.prototype.eat_whitespace = function () {
  while (this.is_whitespace(this.current())) {
    this.eat();
  }
}

Tokenizer.prototype.is_whitespace = function(token) {
  if (0 == token.trim().length) {
    return true;
  } else {
    return false;
  }
}

function TokenizerException(errmsg,errpos) {
  this.name = "TokenizerException";
  this.msg = errmsg;
  this.position = errpos;
}

module.exports = Tokenizer, TokenizerException;
