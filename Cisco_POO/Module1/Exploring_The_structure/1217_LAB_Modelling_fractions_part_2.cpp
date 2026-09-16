#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

class Fraction {
public:
  Fraction(int numerator, int denominator);
  string toString();
  double toDouble();
  Fraction plus(Fraction that);
  Fraction minus(Fraction that);
  Fraction times(Fraction that);
  Fraction by(Fraction that);
private:
  int numerator;
  int denominator;
  void reduce();
  int gcd(int a, int b);
};

Fraction::Fraction(int numerator, int denominator)
{
  this->numerator = numerator;
  this->denominator = denominator;
  reduce();
}

int Fraction::gcd(int a, int b)
{
  a = abs(a);
  b = abs(b);
  while (b != 0)
  {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

void Fraction::reduce()
{
  // normaliza el signo: el denominador siempre queda positivo
  if (denominator < 0)
  {
    numerator = -numerator;
    denominator = -denominator;
  }

  if (numerator == 0)
  {
    denominator = 1;
    return;
  }

  int divisor = gcd(numerator, denominator);
  numerator /= divisor;
  denominator /= divisor;
}

string Fraction::toString()
{
  bool negative = numerator < 0;
  int abs_num = abs(numerator);

  int whole     = abs_num / denominator;
  int remainder = abs_num % denominator;

  ostringstream oss;
  if (negative)
    oss << "-";

  if (remainder == 0)
    oss << whole;
  else if (whole == 0)
    oss << remainder << "/" << denominator;
  else
    oss << whole << " " << remainder << "/" << denominator;

  return oss.str();
}

double Fraction::toDouble()
{
  return static_cast<double>(numerator) / denominator;
}

Fraction Fraction::plus(Fraction that)
{
  int num = this->numerator * that.denominator + that.numerator * this->denominator;
  int den = this->denominator * that.denominator;
  return Fraction(num, den);
}

Fraction Fraction::minus(Fraction that)
{
  int num = this->numerator * that.denominator - that.numerator * this->denominator;
  int den = this->denominator * that.denominator;
  return Fraction(num, den);
}

Fraction Fraction::times(Fraction that)
{
  int num = this->numerator * that.numerator;
  int den = this->denominator * that.denominator;
  return Fraction(num, den);
}

Fraction Fraction::by(Fraction that)
{
  int num = this->numerator * that.denominator;
  int den = this->denominator * that.numerator;
  return Fraction(num, den);
}

int main(void) {
  int num1, den1, num2, den2;
  char slash;

  cin >> num1 >> slash >> den1;
  cin >> num2 >> slash >> den2;

  Fraction f1(num1, den1);
  Fraction f2(num2, den2);

  cout << f1.toString() << " + " << f2.toString() << " = " << f1.plus(f2).toString() << endl;
  cout << f1.toString() << " - " << f2.toString() << " = " << f1.minus(f2).toString() << endl;
  cout << f1.toString() << " * " << f2.toString() << " = " << f1.times(f2).toString() << endl;
  cout << f1.toString() << " / " << f2.toString() << " = " << f1.by(f2).toString() << endl;

  return 0;
}