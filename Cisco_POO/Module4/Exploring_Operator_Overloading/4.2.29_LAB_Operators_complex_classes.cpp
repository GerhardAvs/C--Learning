#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Clase base: guarda el arbol y sabe insertar valores
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}
    virtual ~BinaryTree() { destroy(root); }

    void add(int value) { insert(root, value); }

    // regresa el elemento en la posicion i, segun el recorrido de la clase hija
    int operator[](int index) const {
        vector<int> items;
        traverse(root, items);
        if (index < 0 || index >= (int)items.size())
            throw out_of_range("index out of range");
        return items[index];
    }

    int size() const { return count(root); }

protected:
    struct Node {
        int value;
        Node *left, *right;
        Node(int v) : value(v), left(nullptr), right(nullptr) {}
    };
    Node *root;

    // cada clase hija define el orden del recorrido
    virtual void traverse(Node *node, vector<int> &items) const = 0;

private:
    static void insert(Node *&node, int value) {
        if (!node)
            node = new Node(value);
        else if (value < node->value)
            insert(node->left, value);
        else
            insert(node->right, value);
    }
    static int count(Node *node) { return node ? 1 + count(node->left) + count(node->right) : 0; }
    static void destroy(Node *node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
};

// Imprime usando el operador [] de cada clase
static void printTree(ostream &out, const BinaryTree &tree) {
    for (int i = 0; i < tree.size(); i++)
        out << (i ? " " : "") << tree[i];
}

class Inorder : public BinaryTree {
protected:
    void traverse(Node *n, vector<int> &items) const override {
        if (!n) return;
        traverse(n->left, items);
        items.push_back(n->value);
        traverse(n->right, items);
    }
public:
    friend ostream &operator<<(ostream &out, const Inorder &t) {
        out << "Inorder: ";
        printTree(out, t);
        return out;
    }
};

class Postorder : public BinaryTree {
protected:
    void traverse(Node *n, vector<int> &items) const override {
        if (!n) return;
        traverse(n->left, items);
        traverse(n->right, items);
        items.push_back(n->value);
    }
public:
    friend ostream &operator<<(ostream &out, const Postorder &t) {
        out << "Postorder: ";
        printTree(out, t);
        return out;
    }
};

class Preorder : public BinaryTree {
protected:
    void traverse(Node *n, vector<int> &items) const override {
        if (!n) return;
        items.push_back(n->value);
        traverse(n->left, items);
        traverse(n->right, items);
    }
public:
    friend ostream &operator<<(ostream &out, const Preorder &t) {
        out << "Preorder: ";
        printTree(out, t);
        return out;
    }
};

int main(void) {
    Inorder in;
    Postorder post;
    Preorder pre;
    string word;

    // lee numeros hasta "end"
    while (cin >> word && word != "end") {
        int value = stoi(word);
        in.add(value);
        post.add(value);
        pre.add(value);
    }

    cout << in << endl << post << endl << pre << endl;
    return 0;
}
