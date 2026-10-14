#include <iostream>
using namespace std;

class Fraccion {
private:
    int numerador;
    int denominador;

public:
    Fraccion(int num, int den) {
        numerador = num;
        denominador = den;
    }

    // divide entre el maximo comun divisor para dejarla simplificada
    void simplificar() {
        int a = numerador, b = denominador;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        numerador /= a;
        denominador /= a;
    }

    // suma: a/b + c/d = (a*d + c*b) / (b*d)
    Fraccion operator+(Fraccion otra) {
        int num = numerador * otra.denominador + otra.numerador * denominador;
        int den = denominador * otra.denominador;
        Fraccion resultado(num, den);
        resultado.simplificar();
        return resultado;
    }

    // son equivalentes si a*d == c*b
    bool operator==(Fraccion otra) {
        return numerador * otra.denominador == otra.numerador * denominador;
    }

    void mostrar() {
        cout << numerador << "/" << denominador;
    }
};

int main() {
    // Ejemplo: me comi 1/4 de pizza y mi hermano 2/4
    Fraccion yo(1, 4);
    Fraccion hermano(2, 4);
    Fraccion total = yo + hermano;

    cout << "Pizza que nos comimos: ";
    yo.mostrar();
    cout << " + ";
    hermano.mostrar();
    cout << " = ";
    total.mostrar();
    cout << endl;

    // Comparar fracciones equivalentes
    Fraccion a(1, 2);
    Fraccion b(3, 6);
    Fraccion c(2, 3);

    a.mostrar(); cout << " y "; b.mostrar();
    if (a == b)
        cout << " son equivalentes" << endl;
    else
        cout << " no son equivalentes" << endl;

    a.mostrar(); cout << " y "; c.mostrar();
    if (a == c)
        cout << " son equivalentes" << endl;
    else
        cout << " no son equivalentes" << endl;

    return 0;
}