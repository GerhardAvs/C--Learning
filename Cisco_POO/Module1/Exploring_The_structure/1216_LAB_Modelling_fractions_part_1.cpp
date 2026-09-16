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
private:
  int numerator;
  int denominator;
};

Fraction::Fraction(int numerator, int denominator)
{
  this->numerator = numerator;
  this->denominator = denominator;
}

string Fraction::toString()
{
  bool negative = (numerator < 0) != (denominator < 0);   // XOR de signos
  int abs_num = abs(numerator);
  int abs_den = abs(denominator);

  int whole     = abs_num / abs_den;
  int remainder = abs_num % abs_den;

  ostringstream oss;
  if (negative)
    oss << "-";

  if (remainder == 0)
    oss << whole;                                  // ej: "2"
  else if (whole == 0)
    oss << remainder << "/" << abs_den;             // ej: "3/4"
  else
    oss << whole << " " << remainder << "/" << abs_den;  // ej: "1 3/4"

  return oss.str();
}

double Fraction::toDouble()
{
  return static_cast<double>(numerator) / denominator;
}

// Convierte un double a texto sin ceros finales innecesarios,
// pero conservando al menos un decimal (así 2.0 se ve "2.0", no "2")
string formatDouble(double value)
{
  ostringstream oss;
  oss << fixed << setprecision(10) << value;
  string s = oss.str();

  size_t last = s.find_last_not_of('0');
  if (s[last] == '.')
    last++;          // dejamos un solo cero tras el punto

  s.erase(last + 1);
  return s;
}

int main(void) {
  int  num, den;
  char slash;

  cin >> num >> slash >> den;   // lee "3 / 4", "7 / -4", etc.

  Fraction fraction(num, den);

  cout << fraction.toString() << " is " << formatDouble(fraction.toDouble())
       << " in decimal" << endl;

  return 0;
}