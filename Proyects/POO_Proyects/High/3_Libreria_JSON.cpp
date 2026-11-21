#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>   // libreria externa (sudo pacman -S nlohmann-json)
using namespace std;
using json = nlohmann::json;

class Alumno {
private:
    string nombre;
    json calificaciones;   // objeto JSON: materia -> calificacion

public:
    Alumno(const string& n) : nombre(n) {}

    void agregar(const string& materia, double calif) {
        calificaciones[materia] = calif;
    }

    // Convierte el alumno a JSON y lo guarda en un archivo
    void guardar(const string& archivo) {
        json j;
        j["nombre"] = nombre;
        j["calificaciones"] = calificaciones;
        ofstream(archivo) << j.dump(4);    // dump(4) = con sangria de 4 espacios
        cout << "Guardado en " << archivo << ":\n" << j.dump(4) << endl;
    }

    // Lee el JSON del archivo y calcula el promedio
    static void leerYPromediar(const string& archivo) {
        ifstream entrada(archivo);
        json j = json::parse(entrada);

        double suma = 0;
        for (auto& [materia, calif] : j["calificaciones"].items())
            suma += calif.get<double>();

        cout << "\nPromedio de " << j["nombre"].get<string>() << ": "
             << suma / j["calificaciones"].size() << endl;
    }
};

int main() {
    Alumno a("Gerardo");
    a.agregar("POO", 9.5);
    a.agregar("Calculo", 8.0);
    a.agregar("Fisica", 8.7);

    a.guardar("alumno.json");
    Alumno::leerYPromediar("alumno.json");
    return 0;
}
