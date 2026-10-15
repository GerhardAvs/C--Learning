#include <iostream>
#include <string>
#include <cctype>

class StringValidator
{
public:
  virtual ~StringValidator() {};
  virtual bool isValid(std::string input) = 0;
};

// Your code here
class MinLengthValidator : public StringValidator {
public:
  MinLengthValidator(size_t min) : minLength(min) {}
  bool isValid(std::string input) override {
    return input.length() > minLength;
  }
private:
  size_t minLength;
};

class MaxLengthValidator : public StringValidator {
public:
  MaxLengthValidator(size_t max) : maxLength(max) {}
  bool isValid(std::string input) override {
    return input.length() < maxLength;
  }
private:
  size_t maxLength;
};

class PatternValidator : public StringValidator {
public:
  PatternValidator(const std::string &p) : pattern(p) {}
  bool isValid(std::string input) override {
    if (pattern.empty()) return true;
    if (input.size() < pattern.size()) return false;
    // Busca el patrón en cualquier posición (coincidencia parcial)
    for (size_t start = 0; start + pattern.size() <= input.size(); ++start) {
      if (matchAt(input, start)) return true;
    }
    return false;
  }
private:
  bool matchAt(const std::string &s, size_t start) const {
    for (size_t i = 0; i < pattern.size(); ++i) {
      if (!matchChar(pattern[i], s[start + i])) return false;
    }
    return true;
  }
  static bool matchChar(char p, char c) {
    if (p == '?') return true;                       // cualquier carácter
    if (p == 'D') return std::isdigit((unsigned char)c);  // dígito decimal
    if (p == 'A') return std::isalpha((unsigned char)c);  // letra inglesa
    if (std::isalpha((unsigned char)p))              // letra en minúscula o mayúscula: sin distinguir
      return std::tolower((unsigned char)p) == std::tolower((unsigned char)c);
    return p == c;                                   // puntuación: exacta
  }
  std::string pattern;
};

using namespace std;

void printValid(StringValidator &validator, string input)
{
  cout << "The string '" << input << "' is "
       << (validator.isValid(input) ? "valid" : "invalid") << endl;
}

int main()
{
  cout << "MinLengthValidator" << endl;
  MinLengthValidator min(6);
  printValid(min, "hello");
  printValid(min, "welcome");
  cout << endl;

  cout << "MaxLengthValidator" << endl;
  MaxLengthValidator max(6);
  printValid(max, "hello");
  printValid(max, "welcome");
  cout << endl;

  cout << "PatternValidator" << endl;
  PatternValidator digit("D");
  printValid(digit, "there are 2 types of sentences in the world");
  printValid(digit, "valid and invalid ones");
  cout << endl;

  return 0;
}