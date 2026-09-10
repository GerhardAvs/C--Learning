#include <iostream>
using namespace std;

int main() {
    int calificacion;

    cout << "Ingresa la calificacion (0-100): ";
    cin >> calificacion;

    if (calificacion < 0 || calificacion > 100) {
        cout << "Calificacion invalida." << endl;
    } else if (calificacion < 60) {
        cout << "Resultado: NA (No aprobado)" << endl;
    } else if (calificacion < 70) {
        cout << "Resultado: S (Suficiente)" << endl;
    } else if (calificacion < 80) {
        cout << "Resultado: B (Bien)" << endl;
    } else if (calificacion < 90) {
        cout << "Resultado: MB (Muy bien)" << endl;
    } else {
        cout << "Resultado: E (Excelente)" << endl;
    }

    return 0;
}