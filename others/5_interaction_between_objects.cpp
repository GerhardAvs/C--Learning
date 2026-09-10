#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
    string matricula;
    double promedio;

public:
    Estudiante() {
        nombre = "";
        matricula = "";
        promedio = 0.0;
    }

    Estudiante(string nombre, string matricula, double promedio) {
        this->nombre = nombre;
        this->matricula = matricula;
        this->promedio = promedio;
    }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", Matricula: " << matricula
             << ", Promedio: " << promedio << endl;
    }

    double getPromedio() {
        return promedio;
    }
};

class Grupo {
private:
    static const int CANTIDAD = 3;
    Estudiante estudiantes[CANTIDAD];

public:
    Grupo(Estudiante e1, Estudiante e2, Estudiante e3) {
        estudiantes[0] = e1;
        estudiantes[1] = e2;
        estudiantes[2] = e3;
    }

    void mostrarEstudiantes() {
        for (int i = 0; i < CANTIDAD; i++) {
            estudiantes[i].mostrarInformacion();
        }
    }

    double calcularPromedioGrupal() {
        double suma = 0;
        for (int i = 0; i < CANTIDAD; i++) {
            suma += estudiantes[i].getPromedio();
        }
        return suma / CANTIDAD;
    }
};

int main() {
    Estudiante e1("Gerardo Avalos Sanchez", "vb5223019", 8.5);
    Estudiante e2("Daniel Perez Avalos", "vb2231021", 7.2);
    Estudiante e3("estudiante sin nombre", "vb1234732", 6.0);

    Grupo grupo(e1, e2, e3);

    cout << "Estudiantes del grupo:" << endl;
    grupo.mostrarEstudiantes();

    cout << "Promedio general del grupo: " << grupo.calcularPromedioGrupal() << endl;

    return 0;
}