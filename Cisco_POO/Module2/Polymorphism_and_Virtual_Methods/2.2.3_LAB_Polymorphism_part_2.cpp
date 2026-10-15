#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Field {
    int col; // a=0 ... h=7
    int row; // 1=0 ... 8=7
};

Field parseField(const string& name) {
    Field f;
    f.col = name[0] - 'a';
    f.row = name[1] - '1';
    return f;
}

bool onBoard(const Field& f) {
    return f.col >= 0 && f.col < 8 && f.row >= 0 && f.row < 8;
}

class Piece {
public:
    virtual ~Piece() {}
    virtual bool canMove(const string& from, const string& to) const = 0;
};

class Man : public Piece {
public:
    bool canMove(const string& from, const string& to) const override {
        Field a = parseField(from);
        Field b = parseField(to);
        if (!onBoard(a) || !onBoard(b)) return false;

        int dc = b.col - a.col;
        int dr = b.row - a.row;
        // Solo una casilla hacia adelante, en diagonal
        return dr == 1 && (dc == 1 || dc == -1);
    }
};

class King : public Piece {
public:
    bool canMove(const string& from, const string& to) const override {
        Field a = parseField(from);
        Field b = parseField(to);
        if (!onBoard(a) || !onBoard(b)) return false;

        int dc = b.col - a.col;
        int dr = b.row - a.row;
        // Cualquier distancia, en diagonal, hacia cualquier lado
        return dr != 0 && abs(dc) == abs(dr);
    }
};

int main() {
    Man man;
    King king;

    Piece* m = &man;
    Piece* k = &king;

    cout << boolalpha;
    cout << m->canMove("b1", "c2") << endl; // Man: b1 -> c2
    cout << k->canMove("b1", "d3") << endl; // King: b1 -> d3
    cout << m->canMove("b1", "d3") << endl; // Man: b1 -> d3

    return 0;
}