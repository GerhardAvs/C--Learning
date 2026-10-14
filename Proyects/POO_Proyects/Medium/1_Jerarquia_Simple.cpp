#include <iostream>
#include <string>
using namespace std;

// Clase padre
class Vehiculo {
protected:
    string marca;
    string modelo;
    int velocidadMax; // en km/h

public:
    Vehiculo(string m, string mod, int vel) {
        marca = m;
        modelo = mod;
        velocidadMax = vel;
    }

    virtual void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Velocidad maxima: " << velocidadMax << " km/h" << endl;
    }
};

// Clase hija Auto
class Auto : public Vehiculo {
private:
    int puertas;
    string transmision; // manual o automatica

public:
    Auto(string m, string mod, int vel, int p, string t) : Vehiculo(m, mod, vel) {
        puertas = p;
        transmision = t;
    }

    void mostrarInfo() override {
        cout << "--- AUTO ---" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Velocidad maxima: " << velocidadMax << " km/h" << endl;
        cout << "Puertas: " << puertas << endl;
        cout << "Transmision: " << transmision << endl;
    }
};

// Clase hija Motocicleta
class Motocicleta : public Vehiculo {
private:
    int cilindrada; // en cc

public:
    Motocicleta(string m, string mod, int vel, int cc) : Vehiculo(m, mod, vel) {
        cilindrada = cc;
    }

    void mostrarInfo() override {
        cout << "--- MOTOCICLETA ---" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Velocidad maxima: " << velocidadMax << " km/h" << endl;
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
    }
};

int main() {
    Auto miAuto("Nissan", "Versa 2019", 180, 4, "Manual");
    Motocicleta miMoto("Italika", "FT150", 95, 150);

    miAuto.mostrarInfo();
    cout << endl;
    miMoto.mostrarInfo();

    return 0;
}