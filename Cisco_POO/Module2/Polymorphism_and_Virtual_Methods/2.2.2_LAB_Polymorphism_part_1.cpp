#include <iostream>
using namespace std;

class Tree {
public:
    virtual void draw() = 0;
};

class Tree1 : public Tree {
public:
    void draw() override {
        cout << "Drawing 1:" << endl;
        cout << " /\\" << endl;
        cout << "//\\\\" << endl;
    }
};

class Tree2 : public Tree {
public:
    void draw() override {
        cout << "Drawing 2:" << endl;
        cout << " / \\" << endl;
        cout << "/**\\" << endl;
    }
};

class Tree3 : public Tree {
public:
    void draw() override {
        cout << "Drawing 3:" << endl;
        cout << " / \\" << endl;
        cout << "/++\\" << endl;
    }
};

int main() {
    Tree* trees[3];

    Tree1 t1;
    Tree2 t2;
    Tree3 t3;

    trees[0] = &t1;
    trees[1] = &t2;
    trees[2] = &t3;

    for (int i = 0; i < 3; i++)
        trees[i]->draw();

    return 0;
}