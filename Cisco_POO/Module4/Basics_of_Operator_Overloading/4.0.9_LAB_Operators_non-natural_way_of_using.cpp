#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Stack {
public:
    void push(int value) { items.push_back(value); }

    void pop() {
        if (items.empty())
            throw out_of_range("stack is empty.");
        items.pop_back();
    }

    // consulta el de arriba sin modificar la pila
    int top() const {
        if (items.empty())
            throw out_of_range("stack is empty.");
        return items.back();
    }

    // Uso "no natural" de los operadores:
    //   stack << x  -> push(x)
    //   stack >> x  -> x = top(); pop();
    Stack &operator<<(int value) {
        push(value);
        return *this;
    }

    Stack &operator>>(int &value) {
        value = top();
        pop();
        return *this;
    }

private:
    vector<int> items;
};

int main(void) {
    Stack stack;
    int count, value;

    cin >> count;                  // cuantos elementos meter
    for (int i = 0; i < count; i++) {
        cin >> value;
        stack << value;
    }

    cin >> count;                  // cuantos elementos sacar e imprimir
    try {
        for (int i = 0; i < count; i++) {
            stack >> value;
            cout << value << endl;
        }
    }
    catch (out_of_range &e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}

// Es legitimo? Funciona, pero << y >> normalmente significan "imprimir/leer",
// asi que quien lea el codigo puede confundirse. push() y pop() son mas claros.
