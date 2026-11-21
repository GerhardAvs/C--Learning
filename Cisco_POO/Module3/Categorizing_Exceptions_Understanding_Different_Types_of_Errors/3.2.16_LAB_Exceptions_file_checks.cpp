#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cerrno>

using namespace std;

// Excepciones propias para cada problema de archivo
class FileNotFoundException : public runtime_error {
public:
    FileNotFoundException(const string &path) : runtime_error("File not found at: " + path) {}
};

class NoRightsException : public runtime_error {
public:
    NoRightsException(const string &path) : runtime_error("No rights to write to file: " + path) {}
};

class Matrix2x2 {
public:
    Matrix2x2() : data{{0, 0}, {0, 0}} {}

    // Formato del archivo: 4 numeros separados por espacios
    void load(const string &path) {
        try {
            ifstream file(path);
            if (!file.is_open()) {
                if (errno == EACCES)
                    throw NoRightsException(path);
                throw FileNotFoundException(path);
            }
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    file >> data[i][j];
        }
        catch (runtime_error &e) {
            cout << e.what() << endl;   // imprime el mensaje...
            throw;                      // ...y vuelve a lanzar la excepcion
        }
    }

    void save(const string &path) const {
        try {
            ofstream file(path);
            if (!file.is_open())
                throw NoRightsException(path);
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    file << data[i][j] << (j == 1 ? '\n' : ' ');
        }
        catch (runtime_error &e) {
            cout << e.what() << endl;
            throw;
        }
    }

private:
    int data[2][2];
};

int main(void) {
    Matrix2x2 matrix;

    // Situacion 1: cargar un archivo que no existe
    try {
        matrix.load("nonexistent_matrix.txt");
    }
    catch (FileNotFoundException &) {
        // el mensaje ya se mostro en load(); aqui solo se evita que el programa termine
    }

    // Situacion 2: guardar en una carpeta sin permisos (la raiz del sistema)
    try {
        matrix.save("/matrix.txt");
    }
    catch (NoRightsException &) {
    }

    return 0;
}
