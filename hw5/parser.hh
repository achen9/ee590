#ifndef _PARSER_H_
#define _PARSER_H_

#include "json.hh"

class ParserException : public std::runtime_error {
public:
  ParserException(const char msg[]) : std::runtime_error(msg) {}
};

class Parser {

public:

  Parser ( std::string str );

  Object * object ( void );
  Object * array ( void );
  Object * number ( void );
  Object * hash ( void );
  Object * null ( void );
  Object * boolean ( void );
  Object * string ( void );
  // expression ::= ["-"] term {("+"|"-") term}
  Object * expression(void);
  // term ::= factor {("*"|"/"|"%") factor}
  Object * term(int sign);
  // factor ::= number | "(" expression ")"
  Object * factor(void);

private:

  Tokenizer tok;

};

#endif
