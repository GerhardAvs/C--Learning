#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Engine {
public:
    Engine(const string &version) : version(version) {}
    void print() const {
        cout << "Engine: " << version << "\n";
    }
private:
    string version;
};

class Wheel {
public:
    Wheel(const string &size) : size(size) {}
    void print() const {
        cout << "Wheel: " << size << "\n";
    }
private:
    string size;
};

class Chassis {
public:
    Chassis(const string &type) : type(type) {}
    void print() const {
        cout << "Chassis: " << type << "\n";
    }
private:
    string type;
};

class Light {
public:
    Light(const string &type) : type(type) {}
    void print() const {
        cout << "Light: " << type << "\n";
    }
private:
    string type;
};

class Body {
public:
    Body(const string &color) : color(color) {}
    void print() const {
        cout << "Body: " << color << "\n";
    }
private:
    string color;
};

class Car {
public:
    Car()
        : engine("1.0"),
          wheels{Wheel("16inches"), Wheel("16inches"), Wheel("16inches"), Wheel("16inches")},
          chassis("Normal"),
          lights{Light("Type 1"), Light("Type 1"), Light("Type 2"), Light("Type 2"),
                 Light("Type 3"), Light("Type 3"), Light("Type 4"), Light("Type 4"),
                 Light("Type 5"), Light("Type 5")},
          body("Black") {}

    void print() const {
        engine.print();
        for (const Wheel &w : wheels)
            w.print();
        chassis.print();
        for (const Light &l : lights)
            l.print();
        body.print();
    }

private:
    Engine engine;
    vector<Wheel> wheels;
    Chassis chassis;
    vector<Light> lights;
    Body body;
};

int main() {
    Car car;
    car.print();
    return 0;
}