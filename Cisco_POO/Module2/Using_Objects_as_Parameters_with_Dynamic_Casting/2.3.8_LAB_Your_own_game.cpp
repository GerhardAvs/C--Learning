#include <iostream>
using namespace std;

class Tablero {
public:
    Tablero() {
        for (int i = 0; i < 9; i++)
            casillas[i] = ' ';
    }

    void mostrar() {
        cout << "\n";
        for (int i = 0; i < 9; i++) {
            if (casillas[i] == ' ')
                cout << i + 1;
            else
                cout << casillas[i];

            if (i % 3 < 2)
                cout << " | ";
            else if (i < 6)
                cout << "\n---------\n";
        }
        cout << "\n\n";
    }

    bool estaLibre(int pos) {
        return casillas[pos] == ' ';
    }

    void marcar(int pos, char simbolo) {
        casillas[pos] = simbolo;
    }

    bool hayGanador(char simbolo) {
        int lineas[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
            {0, 4, 8}, {2, 4, 6}
        };
        for (int i = 0; i < 8; i++) {
            if (casillas[lineas[i][0]] == simbolo &&
                casillas[lineas[i][1]] == simbolo &&
                casillas[lineas[i][2]] == simbolo)
                return true;
        }
        return false;
    }

    bool lleno() {
        for (int i = 0; i < 9; i++)
            if (casillas[i] == ' ')
                return false;
        return true;
    }

private:
    char casillas[9];
};

int pedirCasilla(Tablero &t, char simbolo) {
    int pos;
    while (true) {
        cout << "Jugador " << simbolo << ", elige una casilla (1-9): ";
        cin >> pos;

        if (cin.fail() || pos < 1 || pos > 9) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Escribe un numero del 1 al 9.\n";
        } else if (!t.estaLibre(pos - 1)) {
            cout << "Esa casilla ya esta ocupada.\n";
        } else {
            return pos - 1;
        }
    }
}

int main() {
    Tablero tablero;
    char turno = 'X';

    cout << "=== TRES EN RAYA ===\n";
    tablero.mostrar();

    while (true) {
        int pos = pedirCasilla(tablero, turno);
        tablero.marcar(pos, turno);
        tablero.mostrar();

        if (tablero.hayGanador(turno)) {
            cout << "Gana el jugador " << turno << "!\n";
            break;
        }
        if (tablero.lleno()) {
            cout << "Empate.\n";
            break;
        }

        turno = (turno == 'X') ? 'O' : 'X';
    }

    return 0;
}