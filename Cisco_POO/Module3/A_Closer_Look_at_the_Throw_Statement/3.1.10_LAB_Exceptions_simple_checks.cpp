#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Matrix {
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        if (rows < 0 || cols < 0)
            throw invalid_argument("Matrix dimensions can't be negative.");
        data.assign(rows, vector<int>(cols, 0));
    }

    bool isEmpty() const { return rows == 0 || cols == 0; }

    // llena toda la matriz con un valor
    void fill(int value) {
        if (isEmpty())
            throw invalid_argument("Matrix is empty.");
        for (auto &row : data)
            for (int &x : row)
                x = value;
    }

    // suma un valor a cada elemento
    void addValue(int value) {
        if (isEmpty())
            throw invalid_argument("Matrix is empty.");
        for (auto &row : data)
            for (int &x : row)
                x += value;
    }

    // suma otra matriz y regresa el resultado
    Matrix add(const Matrix &other) const {
        if (isEmpty() || other.isEmpty())
            throw invalid_argument("Matrix is empty.");
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrices don't fit.");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    void print() const {
        for (const auto &row : data) {
            for (int j = 0; j < cols; j++)
                cout << (j ? " " : "") << row[j];
            cout << endl;
        }
        cout << endl;
    }

private:
    int rows, cols;
    vector<vector<int>> data;
};

int main(void) {
    int r1, c1, r2, c2, r3, c3;
    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;

    try {
        Matrix m1(r1, c1), m2(r2, c2), m3(r3, c3);
        Matrix *pairs[3][2] = { {&m1, &m2}, {&m1, &m3}, {&m2, &m3} };

        // suma cada par; si no encajan se muestra el error y se sigue con el siguiente
        for (auto &p : pairs) {
            try {
                p[0]->add(*p[1]).print();
            }
            catch (invalid_argument &e) {
                cout << e.what() << endl;
            }
        }
    }
    catch (invalid_argument &e) {
        cout << e.what() << endl;
    }
    return 0;
}

// Otros casos a probar: matriz vacia (0 filas o columnas) en fill, addValue y add,
// y dimensiones negativas al crear la matriz.
