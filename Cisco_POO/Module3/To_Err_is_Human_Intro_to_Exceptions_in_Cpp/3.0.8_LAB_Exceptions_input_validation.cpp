#include <iostream>
using namespace std;
int main(void) {
    int a = 8, b = 0, c = 0;
    cin >> b;
    try {
        // si b es 0 (o el dato no es un numero), se lanza la excepcion a mano
        if (b == 0)
            throw "Your input is not valid, you can't divide by zero.";
        c = a / b;
    }
    catch (const char* message) {
        cout << message << endl;
    }
    cout << c << endl;
    return 0;
}
