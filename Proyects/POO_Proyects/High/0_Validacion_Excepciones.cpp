#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
using namespace std;

// Excepción propia para errores en la edad
class EdadInvalida : public runtime_error {
public:
    EdadInvalida(const string& msg) : runtime_error(msg) {}
};

// Excepción propia para errores en el correo
class CorreoInvalido : public runtime_error {
public:
    CorreoInvalido(const string& msg) : runtime_error(msg) {}
};

// Revisa que la edad sea un número entre 1 y 120
int validarEdad(const string& texto) {
    if (texto.empty())
        throw EdadInvalida("La edad no puede estar vacia");

    for (char c : texto)
        if (!isdigit((unsigned char)c))
            throw EdadInvalida("La edad solo debe tener numeros (escribiste: " + texto + ")");

    if (texto.size() > 3)
        throw EdadInvalida("La edad es demasiado grande");

    int edad = stoi(texto);
    if (edad < 1 || edad > 120)
        throw EdadInvalida("La edad debe estar entre 1 y 120");

    return edad;
}

// Revisa el formato usuario@dominio.ext
void validarCorreo(const string& correo) {
    if (correo.find(' ') != string::npos)
        throw CorreoInvalido("El correo no puede tener espacios");

    size_t arroba = correo.find('@');
    if (arroba == string::npos)
        throw CorreoInvalido("Al correo le falta el @");
    if (arroba == 0)
        throw CorreoInvalido("Falta el usuario antes del @");
    if (correo.find('@', arroba + 1) != string::npos)
        throw CorreoInvalido("El correo solo puede tener un @");

    size_t punto = correo.find('.', arroba);
    if (punto == string::npos || punto == arroba + 1 || punto == correo.size() - 1)
        throw CorreoInvalido("El dominio no es valido (ejemplo: gmail.com)");
}

int main() {
    string textoEdad, correo;

    cout << "Escribe tu edad: ";
    getline(cin, textoEdad);
    cout << "Escribe tu correo: ";
    getline(cin, correo);

    try {
        int edad = validarEdad(textoEdad);   // puede lanzar EdadInvalida
        validarCorreo(correo);               // puede lanzar CorreoInvalido
        cout << "\nDatos correctos: " << edad << " anios, " << correo << endl;
    }
    catch (const EdadInvalida& e) {
        cout << "\n[Error de edad] " << e.what() << endl;
    }
    catch (const CorreoInvalido& e) {
        cout << "\n[Error de correo] " << e.what() << endl;
    }

    return 0;
}
