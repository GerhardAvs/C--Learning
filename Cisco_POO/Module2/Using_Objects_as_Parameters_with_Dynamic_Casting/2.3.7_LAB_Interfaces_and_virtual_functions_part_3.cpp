#include <iostream>
#include <string>
#include <cctype>

class StringValidator
{
public:
  virtual ~StringValidator() {};
  virtual bool isValid(std::string input) = 0;
};

class MinLengthValidator : public StringValidator
{
public:
  MinLengthValidator(int min) : minLength(min) {}
  bool isValid(std::string input) override {
    return (int)input.length() >= minLength;
  }
private:
  int minLength;
};

class MaxLengthValidator : public StringValidator
{
public:
  MaxLengthValidator(int max) : maxLength(max) {}
  bool isValid(std::string input) override {
    return (int)input.length() <= maxLength;
  }
private:
  int maxLength;
};

class LengthValidator : public StringValidator
{
public:
  LengthValidator(int min, int max);
  bool isValid(std::string input) override;
private:
  MinLengthValidator min_validator;
  MaxLengthValidator max_validator;
};

LengthValidator::LengthValidator(int min, int max):
  min_validator(min), max_validator(max)
{
}

bool LengthValidator::isValid(std::string input)
{
  return ( min_validator.isValid(input)
        && max_validator.isValid(input) );
}

// Patrón de un solo carácter, aplicado en cualquier posición del texto
class PatternValidator : public StringValidator
{
public:
  PatternValidator(const std::string &p) : pattern(p) {}
  bool isValid(std::string input) override {
    for (size_t start = 0; start < input.size(); ++start) {
      if (matchChar(pattern[0], input[start])) return true;
    }
    return false;
  }
private:
  static bool matchChar(char p, char c) {
    if (p == 'D') return std::isdigit((unsigned char)c);
    if (p == 'A') return std::isalpha((unsigned char)c);
    if (p == '?') return true;
    if (std::isalpha((unsigned char)p))
      return std::tolower((unsigned char)p) == std::tolower((unsigned char)c);
    return p == c;
  }
  std::string pattern;
};

// Compone las reglas de contraseña: longitud + mayúscula