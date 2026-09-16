#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

class Fraction {
public:
  Fraction(int numerator, int denominator);
  string toString();
  double toDouble();
  bool isGreaterThan(Fraction that);
  bool isLessThan(Fraction that);
  bool isEqual(Fraction that);
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
  bool negative = (numerator < 0) != (denominator < 0);
  int abs_num = abs(numerator);
  int abs_den = abs(denominator);

  int whole     = abs_num / abs_den;
  int remainder = abs_num % abs_den;

  ostringstream oss;
  if (negative)
    oss << "-";

  if (remainder == 0)
    oss << whole;
  else if (whole == 0)
    oss << remainder << "/" << abs_den;
  else
    oss << whole << " " << remainder << "/" << abs_den;

  return oss.str();
}

double Fraction::toDouble()
{
  return static_cast<double>(numerator) / denominator;
}

// Compara a/b vs c/d sin modificar el objeto y sin problemas de signo:
// se normaliza localmente cada denominador a positivo, trasladando
// el signo al numerador, así el producto cruzado siempre es seguro.
bool Fraction::isGreaterThan(Fraction that)
{
  int leftNum  = (this->denominator < 0) ? -this->numerator : this->numerator;
  int leftDen  = abs(this->denominator);
  int rightNum = (that.denominator < 0) ? -that.numerator : that.numerator;
  int rightDen = abs(that.denominator);

  return leftNum * rightDen > rightNum * leftDen;
}

bool Fraction::isLessThan(Fraction that)
{
  return that.isGreaterThan(*this);
}

bool Fraction::isEqual(Fraction that)
{
  return !this->isGreaterThan(that) && !that.isGreaterThan(*this);
}

int main(void) {
  int num1, den1, num2, den2;
  char slash;

  cin >> num1 >> slash >> den1;
  cin >> num2 >> slash >> den2;

  Fraction f1(num1, den1);
  Fraction f2(num2, den2);

  if (f1.isGreaterThan(f2))
    cout << f1.toString() << " > " << f2.toString() << endl;
  else if (f1.isLessThan(f2))
    cout << f1.toString() << " < " << f2.toString() << endl;
  else
    cout << f1.toString() << " = " << f2.toString() << endl;

  return 0;
}