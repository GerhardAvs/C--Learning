#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
    string matricula;
    double promedio;

public:
    Estudiante(string nombre, string matricula, double promedio) {
        this->nombre = nombre;
        this->matricula = matricula;
        this->promedio = promedio;
    }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Matricula: " << matricula << endl;
        cout << "Promedio: " << promedio << endl;
    }

    bool estaEnRiesgo() {
        return promedio < 7.0;
    }
};

int main() {
    Estudiante estudiante1("Gerardo Avalos", "5223019", 8.5);

    estudiante1.mostrarInformacion();

    if (estudiante1.estaEnRiesgo()) {
        cout << "El estudiante esta en riesgo academico." << endl;
    } else {
        cout << "El estudiante no esta en riesgo academico." << endl;
    }

    return 0;
}