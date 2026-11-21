#include <iostream>
#include <string>

using namespace std;
const int DivideByZero = 111;

float internaldiv(float arg1, float arg2)
{
    if (0 == arg2)
        throw DivideByZero;
    return arg1 / arg2;
}

// Version 1: revisa el argumento antes de dividir y lanza su propia excepcion
float div(float arg1, float arg2) {
    if (arg2 == 0.0)
        throw string("Are you kidding me?");
    return arg1 / arg2;
}

// Version 2: no revisa nada, deja que internaldiv lance DivideByZero
float divUnchecked(float arg1, float arg2) {
    return internaldiv(arg1, arg2);
}

int main(void) {
    float r, a, b;
    while (cin >> a) {
        cin >> b;

        // Version 1: el resultado ahora es el valor de retorno, no un parametro
        try {
            r = div(a, b);
            cout << r << endl;
        }
        catch (string &message) {
            cout << message << endl;
        }

        // Version 2: se atrapa la excepcion de division entre cero
        // (solo se imprime el error, el resultado ya se mostro arriba)
        try {
            r = divUnchecked(a, b);
        }
        catch (int code) {
            if (code == DivideByZero)
                cout << "Your input is not valid. You can't divide by zero." << endl;
        }
    }
    return 0;
}

// Cual version es mejor?
// La version 1: revisa los argumentos donde se reciben, el error es claro
// y no depende de que una funcion interna lance algo.
