#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

class Token {

public:

  typedef enum { STRING, DOUBLE, INTEGER, BOOLEAN, PUNCTUATION, NULLTOK } TOKEN_TYPE;

  Token(std::string s) : str(s), token_type(STRING) {}
  Token(const char s[]) : str(s), token_type(STRING) {}
  Token(double d) : dbl(d), token_type(DOUBLE) {}
  Token(int i) : integer(i), token_type(INTEGER) {}
  Token(bool b) : boolean(b), token_type(BOOLEAN) {}
  Token(char c) : punctuation(c), token_type(PUNCTUATION) {}
  Token() : token_type(NULLTOK) {}

  TOKEN_TYPE type() const { return token_type; }

  inline bool matches(char c) { return token_type == PUNCTUATION && punctuation == c; }

  inline bool is_string(void) { return token_type == STRING; }
  inline bool is_bool(void) { return token_type == BOOLEAN; }
  inline bool is_number(void) { return token_type == DOUBLE || token_type == INTEGER; }
  inline bool is_double(void) { return token_type == DOUBLE; }
  inline bool is_int(void) { return token_type == INTEGER; }
  inline bool is_null(void) { return token_type == NULLTOK; }

  inline std::string string_val() { return str; }
  inline double dbl_val() { return dbl; }
  inline int int_val() { return integer; }
  inline bool bool_val() { return boolean; }
  inline char punct_val() { return punctuation; }

  std::string to_s ( void );

  friend std::ostream& operator<<(std::ostream& os, const Token &tok);

private:

  TOKEN_TYPE token_type;
  std::string str;
  double dbl;
  int integer;
  bool boolean;
  char punctuation;

};

#endif
