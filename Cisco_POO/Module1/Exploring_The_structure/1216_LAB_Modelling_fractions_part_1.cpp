#include <iostream>
#include <string>

using namespace std;

class Fraction{
public:
  Fraction(int numerator, int denominator);
  string toString();
  double toDouble();
private:
  int numerator;
  int denominator;
};

// implement Fraction methods

int main(void) {
  int num, den;
  std::string input = "";
  std::cin.getline(input);

  // parse input and get numerator and denominator

  Fraction fraction(num, den);

	cout << fraction.toString() << " is " fraction.toDouble() in decimal << endl;
	return 0;
}