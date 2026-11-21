#include <iostream>

using namespace std;

// Arbol binario de busqueda: menores a la izquierda, mayores o iguales a la derecha
class BinaryTree {
public:
    BinaryTree(int value) : value(value), left(nullptr), right(nullptr) {}
    ~BinaryTree() {
        delete left;
        delete right;
    }

    void add(int newValue) {
        BinaryTree *&child = (newValue < value) ? left : right;
        if (child)
            child->add(newValue);
        else
            child = new BinaryTree(newValue);
    }

    // Va fuera de la clase (friend): el operando izquierdo es ostream, no el arbol
    friend ostream &operator<<(ostream &out, const BinaryTree &tree);

private:
    int value;
    BinaryTree *left;
    BinaryTree *right;
};

// Inorder: izquierda, nodo actual, derecha
ostream &operator<<(ostream &out, const BinaryTree &tree) {
    if (tree.left)
        out << *tree.left;
    out << tree.value << endl;
    if (tree.right)
        out << *tree.right;
    return out;
}

int main(void) {
    int value;
    if (!(cin >> value))
        return 0;

    BinaryTree tree(value);
    while (cin >> value)
        tree.add(value);

    cout << tree;
    return 0;
}
