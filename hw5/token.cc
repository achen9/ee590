#include <string>
#include <iostream>
#include <iomanip>
#include "token.hh"

#define TOKEN_SET_WIDTH 20

std::string Token::to_s ( void ) {

  switch ( token_type ) {

  case PUNCTUATION: {
    std::string s("");
    s += punctuation;
    return s;
  }
  case STRING:
    return str;
  case BOOLEAN:
    return boolean ? std::string("true") : std::string("false");
  case NUMBER:
    return std::to_string(number);
  case NULLTOK:
    return std::string("null");
  default:
    return std::string("UNKNOWN TOKEN");
  }

}

std::ostream& operator<<(std::ostream& os, const Token &tok) {

  switch ( tok.type() ) {

  case Token::NULLTOK:
    os << std::setw(TOKEN_SET_WIDTH) << std::left << "NULLTOK: null";
    break;

  case Token::NUMBER:
    os << "NUMBER: " << std::setw(TOKEN_SET_WIDTH - 8) << std::left << tok.number;
    break;

  case Token::STRING:
    os << "STRING: " << std::setw(TOKEN_SET_WIDTH - 8) << std::left << tok.str;
    break;

  case Token::BOOLEAN:
    os << "BOOLEAN: " << std::setw(TOKEN_SET_WIDTH - 9) << std::left << ( tok.boolean ? "true" : "false" );
    break;

  case Token::PUNCTUATION:
    os << "PUNCTUATION: " << std::setw(TOKEN_SET_WIDTH - 13) << std::left << tok.punctuation;
    break;

  default:
    os << std::setw(TOKEN_SET_WIDTH) << std::left << "!UNKNOWN TOKEN!";
    break;

  }
  return os;

}
