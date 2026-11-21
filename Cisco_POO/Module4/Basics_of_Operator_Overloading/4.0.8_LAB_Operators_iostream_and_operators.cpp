#include <iostream>

using namespace std;

// Contenedor de una matriz 2x2
class Matrix2x2 {
public:
    Matrix2x2() : data{{0, 0}, {0, 0}} {}

    // >> lee los 4 valores, << imprime la matriz
    friend istream &operator>>(istream &in, Matrix2x2 &m);
    friend ostream &operator<<(ostream &out, const Matrix2x2 &m);

private:
    int data[2][2];
};

istream &operator>>(istream &in, Matrix2x2 &m) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            in >> m.data[i][j];
    return in;
}

ostream &operator<<(ostream &out, const Matrix2x2 &m) {
    for (int i = 0; i < 2; i++)
        out << m.data[i][0] << " " << m.data[i][1] << endl;
    return out;
}

int main(void) {
    Matrix2x2 matrix;      // solo el constructor
    cin >> matrix;         // valores con el operador >>
    cout << matrix;        // impresion con el operador <<
    return 0;
}
