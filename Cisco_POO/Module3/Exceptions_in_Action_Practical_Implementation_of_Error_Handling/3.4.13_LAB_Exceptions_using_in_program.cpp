#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Las tres excepciones que pide el lab
class WrongTowerException : public runtime_error {
public:
    WrongTowerException() : runtime_error("Incorrect input - towers must be in the 1-3 range.") {}
};

class WrongDiskSizeException : public runtime_error {
public:
    WrongDiskSizeException() : runtime_error("Incorrect input - the disk is bigger than the one on the target tower.") {}
};

class EmptyTowerException : public runtime_error {
public:
    EmptyTowerException() : runtime_error("Incorrect input - there are no disks on the source tower.") {}
};

class Hanoi {
public:
    Hanoi() : towers(3) {
        towers[0] = {3, 2, 1};   // el ultimo elemento es el disco de arriba
    }

    // Mueve el disco de arriba de 'from' a 'to' (torres 1-3)
    void move(int from, int to) {
        if (from < 1 || from > 3 || to < 1 || to > 3)
            throw WrongTowerException();
        if (from == to)
            return;              // 11, 22, 33: movimiento vacio pero correcto

        vector<int> &source = towers[from - 1];
        vector<int> &target = towers[to - 1];

        if (source.empty())
            throw EmptyTowerException();
        if (!target.empty() && source.back() > target.back())
            throw WrongDiskSizeException();

        target.push_back(source.back());
        source.pop_back();
    }

    void print() const {
        for (int i = 0; i < 3; i++) {
            cout << "tower_" << i + 1 << ":";
            if (towers[i].empty())
                cout << " empty";
            for (int disk : towers[i])
                cout << " " << disk;
            cout << endl;
        }
    }

private:
    vector<vector<int>> towers;
};

int main(void) {
    Hanoi hanoi;
    int command;

    // 12 = mover de la torre 1 a la 2; 0 = terminar
    while (cin >> command && command != 0) {
        try {
            hanoi.move(command / 10, command % 10);
        }
        catch (runtime_error &e) {
            cout << e.what() << endl;
        }
    }

    hanoi.print();
    return 0;
}
