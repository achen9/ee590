#include "object.hh"

class Number : public Object {

public:

  Number(double d);
  Number(int i);
  Number(const Number &number) { d_value = number.d_value; \
    i_value = number.i_value; is_integer = number.is_integer; }

  Number * clone() { return new Number(*this); }
  inline void set_d(double d) { d_value = d; is_integer = false; }
  inline void set_i(int i) { i_value = i; is_integer = true; }
  double get_d(void) const;
  int get_i(void) const;
  inline bool is_int(void) const { return is_integer; }
  std::string stringify();

private:

  double d_value;
  int i_value;
  bool is_integer;
};
