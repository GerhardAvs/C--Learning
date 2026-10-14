#include <iostream>
#include <string>
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
    // arreglo de apuntadores a Vehiculo, pero guardamos autos y motos
    Vehiculo* estacionamiento[4];

    estacionamiento[0] = new Auto("Chevrolet", "Aveo 2018", 170, 4);
    estacionamiento[1] = new Motocicleta("Honda", "CGL 125", 100, 125);
    estacionamiento[2] = new Auto("Volkswagen", "Jetta 2015", 190, 4);
    estacionamiento[3] = new Motocicleta("Yamaha", "FZ 2.0", 120, 150);

    cout << "Vehiculos en el estacionamiento:" << endl;
    for (int i = 0; i < 4; i++) {
        estacionamiento[i]->mostrarInfo(); // cada uno llama a su propia version
    }

    // liberar memoria
    for (int i = 0; i < 4; i++) {
        delete estacionamiento[i];
    }

    return 0;
}