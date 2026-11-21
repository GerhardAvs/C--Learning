#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Matrix {
public:
    Matrix(int rows, int cols, int value = 0) : rows(rows), cols(cols) {
        if (rows <= 0 || cols <= 0)
            throw invalid_argument("Matrix size must be greater than 0");
        data.assign(rows, vector<int>(cols, value));
    }

    int &at(int r, int c) { return data[r][c]; }

    // Matriz con un valor (a cada celda)
    Matrix operator+(int value) const { return apply([value](int x) { return x + value; }); }
    Matrix operator-(int value) const { return apply([value](int x) { return x - value; }); }
    Matrix operator*(int value) const { return apply([value](int x) { return x * value; }); }

    // Matriz con matriz
    Matrix operator+(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix sizes do not match for addition");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator-(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix sizes do not match for subtraction");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    // Se puede multiplicar si las columnas de A son iguales a las filas de B
    Matrix operator*(const Matrix &other) const {
        if (cols != other.rows)
            throw invalid_argument("Matrix sizes do not match for multiplication");
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    friend ostream &operator<<(ostream &out, const Matrix &m) {
        for (const auto &row : m.data) {
            for (int j = 0; j < m.cols; j++)
                out << (j ? " " : "") << row[j];
            out << endl;
        }
        return out;
    }

private:
    int rows, cols;
    vector<vector<int>> data;

    template <typename F>
    Matrix apply(F f) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = f(data[i][j]);
        return result;
    }
};

// Pide tamano y valores de una matriz
Matrix readMatrix(const string &name) {
    int rows, cols;
    cout << "Enter the number of rows for Matrix " << name << ": ";
    cin >> rows;
    cout << "Enter the number of columns for Matrix " << name << ": ";
    cin >> cols;

    Matrix m(rows, cols);
    cout << "Enter the values for Matrix " << name << ":" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            cout << "Enter value at position [" << i << "][" << j << "]: ";
            cin >> m.at(i, j);
        }
    return m;
}

int main(void) {
    try {
        string operation;
        cout << "Enter the operation you want to perform (add, subtract, multiply): ";
        cin >> operation;

        Matrix a = readMatrix("A");
        Matrix b = readMatrix("B");

        cout << endl << "Matrix A:" << endl << a << endl;
        cout << "Matrix B:" << endl << b << endl;

        // primero se calcula; si lanza excepcion no se imprime el titulo a medias
        if (operation == "add") {
            Matrix result = a + b;
            cout << "After addition:" << endl << result;
        }
        else if (operation == "subtract") {
            Matrix result = a - b;
            cout << "After subtraction:" << endl << result;
        }
        else if (operation == "multiply") {
            Matrix result = a * b;
            cout << "After multiplication:" << endl << result;
        }
        else
            throw invalid_argument("Unknown operation: " + operation);
    }
    catch (invalid_argument &e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
