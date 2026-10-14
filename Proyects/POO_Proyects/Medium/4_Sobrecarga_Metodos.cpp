#include <iostream>
using namespace std;

class Calculadora {
public:
    // dos enteros
    int sumar(int a, int b) {
        return a + b;
    }

    // tres enteros
    int sumar(int a, int b, int c) {
        return a + b + c;
    }

    // dos decimales
    double sumar(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculadora calc;

    // horas que estudie lunes y martes
    cout << "Horas de estudio (lun + mar): " << calc.sumar(2, 3) << endl;

    // calificaciones de los 3 parciales
    cout << "Suma de parciales: " << calc.sumar(8, 9, 7) << endl;

    // gasto en la tienda: refresco + papas
    cout << "Total en la tienda: $" << calc.sumar(18.50, 22.00) << endl;

    return 0;
}