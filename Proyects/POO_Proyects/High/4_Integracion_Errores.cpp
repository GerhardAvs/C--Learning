#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sqlite3.h>
using namespace std;

// Excepciones propias
class ArchivoNoEncontrado : public runtime_error {
public:
    ArchivoNoEncontrado(const string& nombre)
        : runtime_error("El archivo '" + nombre + "' no existe") {}
};

class ErrorBaseDatos : public runtime_error {
public:
    ErrorBaseDatos(const string& msg) : runtime_error(msg) {}
};

// Lee un archivo de texto; lanza excepcion si no existe
void leerArchivo(const string& nombre) {
    ifstream entrada(nombre);
    if (!entrada.is_open())
        throw ArchivoNoEncontrado(nombre);

    string linea;
    while (getline(entrada, linea))
        cout << "  " << linea << endl;
}

// Abre una BD ya existente y consulta productos; lanza excepcion si algo falla
void consultarBD(const string& archivo) {
    sqlite3* db = nullptr;

    // SQLITE_OPEN_READWRITE sin CREATE: falla si el archivo no existe
    if (sqlite3_open_v2(archivo.c_str(), &db, SQLITE_OPEN_READWRITE, nullptr) != SQLITE_OK) {
        string msg = "No se pudo conectar a '" + archivo + "': " + sqlite3_errmsg(db);
        sqlite3_close(db);
        throw ErrorBaseDatos(msg);
    }

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, "SELECT nombre, precio FROM productos;", -1, &stmt, nullptr) != SQLITE_OK) {
        string msg = string("Error en la consulta: ") + sqlite3_errmsg(db);
        sqlite3_close(db);
        throw ErrorBaseDatos(msg);
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
        cout << "  " << sqlite3_column_text(stmt, 0) << " - $" << sqlite3_column_double(stmt, 1) << endl;

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main() {
    int opcion;
    string nombre;

    do {
        cout << "\n1. Leer archivo de texto\n2. Consultar base de datos\n0. Salir\nOpcion: ";
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = -1;
        }

        try {
            switch (opcion) {
                case 1:
                    cout << "Nombre del archivo (ej: tareas.txt): ";
                    cin >> nombre;
                    leerArchivo(nombre);
                    break;
                case 2:
                    cout << "Nombre de la base de datos (ej: tienda.db): ";
                    cin >> nombre;
                    consultarBD(nombre);
                    break;
                case 0:
                    cout << "Adios" << endl;
                    break;
                default:
                    cout << "Opcion no valida" << endl;
            }
        }
        catch (const ArchivoNoEncontrado& e) {
            cout << "[Error de archivo] " << e.what() << endl;
        }
        catch (const ErrorBaseDatos& e) {
            cout << "[Error de base de datos] " << e.what() << endl;
        }
    } while (opcion != 0);   // el programa sigue aunque haya errores

    return 0;
}
