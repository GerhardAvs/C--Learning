#include <iostream>
using namespace std;

int main() {
    double num1, num2, resultado;
    char operador;

    cout << "Ingresa el primer numero: ";
    cin >> num1;

    cout << "Ingresa el operador (+, -, *, /): ";
    cin >> operador;

    cout << "Ingresa el segundo numero: ";
    cin >> num2;

    switch (operador) {
        case '+':
            resultado = num1 + num2;
            cout << "Resultado: " << resultado << endl;
            break;
        case '-':
            resultado = num1 - num2;
            cout << "Resultado: " << resultado << endl;
            break;
        case '*':
            resultado = num1 * num2;
            cout << "Resultado: " << resultado << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error: no se puede dividir entre cero." << endl;
            } else {
                resultado = num1 / num2;
                cout << "Resultado: " << resultado << endl;
            }
            break;
        default:
            cout << "Operador invalido." << endl;
    }

    return 0;
}