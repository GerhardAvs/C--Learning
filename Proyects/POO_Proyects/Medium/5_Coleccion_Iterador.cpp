#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    int velocidadMax;

public:
    Vehiculo(string m, string mod, int vel) {
        marca = m;
        modelo = mod;
        velocidadMax = vel;
    }

    virtual void mostrarInfo() {
        cout << marca << " " << modelo << " - " << velocidadMax << " km/h" << endl;
    }

    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
private:
    int puertas;

public:
    Auto(string m, string mod, int vel, int p) : Vehiculo(m, mod, vel) {
        puertas = p;
    }

    void mostrarInfo() override {
        cout << "[Auto] " << marca << " " << modelo
             << " | Vel. max: " << velocidadMax << " km/h"
             << " | Puertas: " << puertas << endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    Motocicleta(string m, string mod, int vel, int cc) : Vehiculo(m, mod, vel) {
        cilindrada = cc;
    }

    void mostrarInfo() override {
        cout << "[Moto] " << marca << " " << modelo
             << " | Vel. max: " << velocidadMax << " km/h"
             << " | Cilindrada: " << cilindrada << " cc" << endl;
    }
};

int main() {
    // lista de vehiculos de mi familia
    vector<Vehiculo*> vehiculos;

    vehiculos.push_back(new Auto("Nissan", "Tsuru 2012", 165, 4));
    vehiculos.push_back(new Auto("Kia", "Rio 2021", 180, 4));
    vehiculos.push_back(new Motocicleta("Italika", "DM150", 90, 150));
    vehiculos.push_back(new Motocicleta("Suzuki", "GN125", 100, 125));

    cout << "Vehiculos de la familia:" << endl;

    // recorrer con iterador
    vector<Vehiculo*>::iterator it;
    for (it = vehiculos.begin(); it != vehiculos.end(); it++) {
        (*it)->mostrarInfo();
    }

    // liberar memoria
    for (it = vehiculos.begin(); it != vehiculos.end(); it++) {
        delete *it;
    }

    return 0;
}