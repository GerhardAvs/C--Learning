#include <iostream>
#include <string>

using namespace std;

class Fraction{
public:
  Fraction(int numerator, int denominator);
  string toString();
  double toDouble();
  // the functions below do not change the object
  // on which they are called, they produce a new object
  Fraction plus(Fraction that);
  Fraction minus(Fraction that);
  Fraction times(Fraction that);
  Fraction by(Fraction that);
private:
  int numerator;
  int denominator;
  void reduce();
};

Fraction::times(Fraction that)
{
  int num = this->numerator * that.denominator;
  int den = this->denominator * that.denominator;
  Fraction result(num, den);
  // we could call result.reduce() here
  // or use it just before it is necessary
  return result;

// implement other Fraction methods
}