#include <iostream>
#include <stdexcept>

using namespace std;

// Guarda un valor y sus limites [min, max]
class LimitedValue {
public:
    LimitedValue(int value, int min, int max) : value(value), min(min), max(max) {}

    void add(int x) {
        if (value + x > max || value + x < min)
            throw out_of_range("Value could exceed limit.");
        value += x;
    }

    void subtract(int x) {
        if (value - x > max || value - x < min)
            throw out_of_range("Value could exceed limit.");
        value -= x;
    }

    int getValue() const { return value; }

private:
    int value, min, max;
};

int main(void) {
    int value, min, max;
    cin >> value >> min >> max;
    LimitedValue first(value, min, max);
    cin >> value >> min >> max;
    LimitedValue second(value, min, max);

    int x;

    cin >> x;                       // 5 + 15 = 20 > 10
    try { first.add(x); }
    catch (out_of_range &e) { cout << e.what() << endl; }

    cin >> x;                       // 9 + 15 = 24, cabe
    try { second.add(x); }
    catch (out_of_range &e) { cout << e.what() << endl; }

    cin >> x;                       // 24 - 90 = -66 < 0
    try { second.subtract(x); }
    catch (out_of_range &e) { cout << e.what() << endl; }

    cout << first.getValue() << endl;
    cout << second.getValue() << endl;
    return 0;
}
