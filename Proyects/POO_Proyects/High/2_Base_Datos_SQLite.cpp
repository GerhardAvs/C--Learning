#include <iostream>
#include <string>
#include <sqlite3.h>
using namespace std;

class BaseDatos {
private:
    sqlite3* db = nullptr;

public:
    // Abre (o crea) el archivo de la base de datos
    BaseDatos(const string& archivo) {
        if (sqlite3_open(archivo.c_str(), &db) != SQLITE_OK)
            cout << "Error al abrir: " << sqlite3_errmsg(db) << endl;
    }

    // Cierra la conexion al destruir el objeto
    ~BaseDatos() { sqlite3_close(db); }

    // Ejecuta SQL que no regresa filas (CREATE, DELETE...)
    void ejecutar(const string& sql) {
        char* error = nullptr;
        if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &error) != SQLITE_OK) {
            cout << "Error SQL: " << error << endl;
            sqlite3_free(error);
        }
    }

    // Inserta un producto con una consulta preparada (evita inyeccion SQL)
    void insertarProducto(const string& nombre, double precio) {
        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, "INSERT INTO productos (nombre, precio) VALUES (?, ?);", -1, &stmt, nullptr);
        sqlite3_bind_text(stmt, 1, nombre.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, 2, precio);
        if (sqlite3_step(stmt) != SQLITE_DONE)
            cout << "Error al insertar: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
    }

    // Consulta todos los productos y los imprime
    void mostrarProductos() {
        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, "SELECT id, nombre, precio FROM productos;", -1, &stmt, nullptr);
        cout << "ID | Nombre | Precio" << endl;
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            cout << sqlite3_column_int(stmt, 0) << " | "
                 << sqlite3_column_text(stmt, 1) << " | $"
                 << sqlite3_column_double(stmt, 2) << endl;
        }
        sqlite3_finalize(stmt);
    }
};

int main() {
    BaseDatos db("tienda.db");

    db.ejecutar("DROP TABLE IF EXISTS productos;");   // empieza limpio en cada ejecucion
    db.ejecutar("CREATE TABLE productos ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "nombre TEXT NOT NULL,"
                "precio REAL NOT NULL);");

    db.insertarProducto("Refresco", 18.50);
    db.insertarProducto("Papas", 22.00);
    db.insertarProducto("Galletas", 15.75);

    db.mostrarProductos();
    return 0;
}
