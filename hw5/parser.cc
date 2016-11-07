#include "parser.hh"
#include "token.hh"

Parser::Parser ( std::string str ) : tok(str) {
}

Object * Parser::array ( void ) {

  Array * a = new Array();

  tok.eat_punctuation('[');
  int i = 0;

  while ( !tok.current().matches(']') ) {
    a->set(i++,object());
    if ( tok.current().matches(',')) {
      tok.eat_punctuation(',');
      if ( tok.current().matches(']') ) {
        throw ParserException("Unexpected end of array");
      }
    }
  }

  tok.eat_punctuation(']');

  return a;

}

Object * Parser::hash ( void ) {

  Hash * h = new Hash();

  tok.eat_punctuation('{');

  while ( !tok.current().matches('}') ) {

    if ( tok.current().is_string() ) {

std::string key = tok.current().string_val();
tok.eat();
tok.eat_punctuation(':');
h->set(key, object());

if (tok.current().matches(',')) {
  tok.eat_punctuation(',');
  if (tok.current().matches('}')) {
    throw ParserException("Unexpected end of hash");
  }
}

    } else {

    throw ParserException("Expected string");

    }

  }

  tok.eat_punctuation('}');

  return h;

}

/*Object * Parser::number(void) {
  Number * n = new Number(tok.current().number_val());
  tok.eat();
  return n;
}*/

Object * Parser::null(void) {
  tok.eat();
  return new Null;
}

Object * Parser::boolean(void) {
  Boolean * b = new Boolean(tok.current().bool_val());
  tok.eat();
  return b;
}

Object * Parser::string(void) {
  String * s = new String(tok.current().string_val());
  tok.eat();
  return s;
}

Object * Parser::expression(void) {
  Object * n;
  Object * t1;
  if (tok.current().matches('-')) {
    tok.eat();
    t1 = term(-1);
  } else {
    t1 = term(1);
  }
  // Apply negative sign to first term
  if (t1->is_int()) {
   // n->set_i(n->get_i() * t1->get_i());
    n = new Number(t1->get_i());
  } else {
    //n->set_d((double)n->get_i() * t1->get_d());
    n = new Number(t1->get_d());
  }
  // Find second term & apply operation as long as more '-' or '+'
  // tokens found
  while (tok.current().matches('-') || tok.current().matches('+')) {
    if (tok.current().matches('-')) {
      tok.eat();
      Object * t2 = term(1);
      if (t2->is_int() && n->is_int()) {
        n->set_i(n->get_i() - t2->get_i());
      } else if (t2->is_int() && !n->is_int()) {
        n->set_d(n->get_d() - (double)t2->get_i());
      } else if (!t2->is_int() && n->is_int()) {
        n->set_d((double)n->get_i() - t2->get_d());
      } else {
        n->set_d(n->get_d() - t2->get_d());
      }
    } else if (tok.current().matches('+')) {
      tok.eat();
      Object *t2 = term(1);
      if (t2->is_int() && n->is_int()) {
        n->set_i(n->get_i() + t2->get_i());
      } else if (t2->is_int() && !n->is_int()) {
        n->set_d(n->get_d() + (double)t2->get_i());
      } else if (!t2->is_int() && n->is_int()) {
        n->set_d((double)n->get_i() + t2->get_d());
      } else {
        n->set_d(n->get_d() + t2->get_d());
      }
    } 
  }
  return n;
}

Object * Parser::term(int sign) {
  Object * n = new Number(1);
  Object * f1 = factor();
  if (f1->is_int()) {
    n->set_i(sign * f1->get_i());
  } else {
    n->set_d((double)sign * f1->get_d());
  }
  while (tok.current().matches('*') || tok.current().matches('/') || tok.current().matches('%')) {
    if (tok.current().matches('*')) {
      tok.eat();
      Object * f2 = factor();
      if (f2->is_int() && n->is_int()) {
        n->set_i(n->get_i() * f2->get_i());
      } else if (f2->is_int() && !n->is_int()) {
        n->set_d(n->get_d() * (double)f2->get_i());
      } else if (!f2->is_int() && n->is_int()) {
        n->set_d((double)n->get_i() * f2->get_d());
      } else {
        n->set_d(n->get_d() * f2->get_d());
      }
    } else if (tok.current().matches('/')) {
      tok.eat();
      Object * f2 = factor();
      if (f2->is_int() && n->is_int()) {
        n->set_i(n->get_i() / f2->get_i());
      } else if (f2->is_int() && !n->is_int()) {
        n->set_d(n->get_d() / (double)f2->get_i());
      } else if (!f2->is_int() && n->is_int()) {
        n->set_d((double)n->get_i() / f2->get_d());
      } else {
        n->set_d(n->get_d() / f2->get_d());
      }
    } else if (tok.current().matches('%')) {
      tok.eat();
      Object * f2 = factor();
      if (f2->is_int() && n->is_int()) {
        n->set_i(n->get_i() % f2->get_i());
      } else {
        throw ParserException("Tried to compute modulo between non-int values.");
      }
    }
  }
  return n;
}

Object * Parser::factor(void) {
  if (tok.current().matches('(')) {
    tok.eat();
    Object * n = expression();
    if (tok.current().matches(')')) {
      tok.eat();
      return n;
    } else {
      throw ParserException("Expected ')' token at end of expression.");
    }
  } else if (tok.current().is_number()) {
    Object * n;
    if (tok.current().is_int()) {
      n = new Number(tok.current().int_val());
    } else {
      n = new Number(tok.current().dbl_val());
    }
    tok.eat();
    return n;
  } else {
    throw ParserException("Non-valid factor token encounted.");
  }
}

Object * Parser::object(void) {

  if (tok.current().matches('{')) {
    return hash();
  } else if (tok.current().matches('[')) {
    return array();
  } else if (tok.current().is_number() || tok.current().matches('-') || tok.current().matches('(')) {
    return expression();
  } else if ( tok.current().is_null() ) {
    return null();
  } else if ( tok.current().is_bool() ) {
    return boolean();
  } else if ( tok.current().is_string() ) {
    return string();
  } else {
    std::string s("Unexpected token ");
    s += tok.current().to_s();
    throw ParserException(s.c_str());
  }

}
