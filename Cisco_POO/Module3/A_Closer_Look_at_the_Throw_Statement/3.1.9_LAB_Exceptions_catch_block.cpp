#include <iostream>
#include <string>

using namespace std;

// Excepcion propia con un atributo para el mensaje al usuario
class AreaException {
public:
    AreaException(const string &message) : message(message) {}
    string getMessage() const { return message; }
private:
    string message;
};

// Una funcion por figura; los lados deben ser mayores que 0
float square_area(float side) {
    if (side <= 0)
        throw AreaException("Your input is not valid. The area can't be negative.");
    return side * side;
}

float rectangle_area(float width, float height) {
    if (width <= 0 || height <= 0)
        throw AreaException("Your input is not valid. The area can't be negative.");
    return width * height;
}

int main(void) {
    float a, b;
    cin >> a;
    cin >> b;
    try
    {
        float rsquare = square_area(a);
        float rrectangle = rectangle_area(a, b);
        cout << rsquare << endl << rrectangle << endl;
    }
    catch (AreaException &e)
    {
        cout << e.getMessage() << endl;
    }
    return 0;
}
