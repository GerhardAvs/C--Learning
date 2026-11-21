#include <iostream>
#include <string>
#include <cctype>

class StringValidator
{
public:
  virtual ~StringValidator() {}
  virtual bool isValid(const std::string &input) const = 0;
};

class MinLengthValidator : public StringValidator
{
public:
  explicit MinLengthValidator(int min) : minLength(min) {}
  bool isValid(const std::string &input) const override {
    return (int)input.length() >= minLength;
  }
private:
  int minLength;
};

class MaxLengthValidator : public StringValidator
{
public:
  explicit MaxLengthValidator(int max) : maxLength(max) {}
  bool isValid(const std::string &input) const override {
    return (int)input.length() <= maxLength;
  }
private:
  int maxLength;
};

class LengthValidator : public StringValidator
{
public:
  LengthValidator(int min, int max) : min_validator(min), max_validator(max) {}
  bool isValid(const std::string &input) const override {
    return min_validator.isValid(input) && max_validator.isValid(input);
  }
private:
  MinLengthValidator min_validator;
  MaxLengthValidator max_validator;
};

// Patrón de un solo carácter, aplicado en cualquier posición del texto
class PatternValidator : public StringValidator
{
public:
  explicit PatternValidator(const std::string &p) : pattern(p) {
    if (pattern.empty()) {
      throw std::invalid_argument("El patrón no puede estar vacío");
    }
  }
  bool isValid(const std::string &input) const override {
    for (char c : input) {
      if (matchChar(pattern[0], c)) return true;
    }
    return false;
  }
private:
  static bool matchChar(char p, char c) {
    if (p == 'D') return std::isdigit((unsigned char)c);
    if (p == 'A') return std::isalpha((unsigned char)c);
    if (p == '?') return true;
    return p == c; // comparación exacta: distingue mayúsculas
  }
  std::string pattern;
};

class UppercaseValidator : public StringValidator
{
public:
  bool isValid(const std::string &input) const override {
    for (char c : input) {
      if (std::isupper((unsigned char)c)) return true;
    }
    return false;
  }
};

// Compone las reglas de contraseña: longitud + al menos una mayúscula
class PasswordValidator : public StringValidator
{
public:
  PasswordValidator(int min, int max) : length(min, max) {}
  bool isValid(const std::string &input) const override {
    return length.isValid(input) && upper.isValid(input);
  }
private:
  LengthValidator length;
  UppercaseValidator upper;
};

int main()
{
  PasswordValidator pv(8, 16);

  std::cout << pv.isValid("hola1234") << "\n";   // 0: sin mayúscula
  std::cout << pv.isValid("Hola1234") << "\n";   // 1
  std::cout << pv.isValid("Ho") << "\n";         // 0: muy corta

  PatternValidator pat("A");
  std::cout << pat.isValid("abc") << "\n";       // 1: hay una letra
  std::cout << pat.isValid("123") << "\n";       // 0
}