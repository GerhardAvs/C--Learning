#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class ListaTareas {
private:
    string archivo;           // nombre del archivo de texto
    vector<string> tareas;    // tareas que se van a guardar

public:
    ListaTareas(const string& nombreArchivo) : archivo(nombreArchivo) {
        tareas = {
            "Terminar la tarea de POO",
            "Estudiar para el parcial de Calculo",
            "Lavar la ropa",
            "Ir al gimnasio",
            "Comprar despensa"
        };
    }

    // Escribe una tarea por linea
    void guardar() {
        ofstream salida(archivo);
        if (!salida.is_open()) {
            cout << "No se pudo crear " << archivo << endl;
            return;
        }
        for (const string& t : tareas)
            salida << t << endl;
        cout << "Se guardaron " << tareas.size() << " tareas en " << archivo << endl;
    }

    // Lee el archivo linea por linea y lo muestra
    void leer() {
        ifstream entrada(archivo);
        if (!entrada.is_open()) {
            cout << "No existe " << archivo << ". Primero usa la opcion 1." << endl;
            return;
        }
        string linea;
        int n = 1;
        cout << "Tareas pendientes:" << endl;
        while (getline(entrada, linea))
            cout << "  " << n++ << ". " << linea << endl;
    }
};

int main() {
    ListaTareas lista("tareas.txt");
    int opcion;

    do {
        cout << "\n1. Guardar tareas\n2. Leer tareas\n0. Salir\nOpcion: ";
        if (!(cin >> opcion)) {        // si escriben letras
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = -1;
        }

        switch (opcion) {
            case 1: lista.guardar(); break;
            case 2: lista.leer(); break;
            case 0: cout << "Adios" << endl; break;
            default: cout << "Opcion no valida" << endl;
        }
    } while (opcion != 0);

    return 0;
}
