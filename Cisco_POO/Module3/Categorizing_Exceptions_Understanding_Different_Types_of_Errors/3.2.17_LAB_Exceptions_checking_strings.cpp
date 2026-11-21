#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

class IPAddress {
public:
    // El constructor lanza excepcion si el texto no es una IP valida
    IPAddress(const string &text) {
        stringstream ss(text);
        string part;
        int count = 0;

        while (getline(ss, part, '.')) {
            if (count == 4 || part.empty() || part.size() > 3)
                throw invalid_argument("invalid IP number.");
            for (char c : part)
                if (c < '0' || c > '9')
                    throw invalid_argument("invalid IP number.");
            int value = stoi(part);
            if (value > 255)
                throw invalid_argument("invalid IP number.");
            octets[count++] = value;
        }
        if (count != 4 || text.back() == '.')
            throw invalid_argument("invalid IP number.");
    }

    // Imprime las siguientes 'range' direcciones; range debe ser potencia de 2 (1..256)
    void print(int range) const {
        bool powerOfTwo = range > 0 && (range & (range - 1)) == 0;
        if (!powerOfTwo || range > 256 || octets[3] + range > 255)
            throw invalid_argument("invalid range.");

        for (int i = 1; i <= range; i++)
            cout << octets[0] << "." << octets[1] << "." << octets[2] << "."
                 << octets[3] + i << endl;
        cout << endl;
    }

private:
    int octets[4];
};

int main(void) {
    string ip;
    int range;

    // cada linea: IP rango
    while (cin >> ip >> range) {
        try {
            IPAddress address(ip);
            address.print(range);
        }
        catch (invalid_argument &e) {
            cout << "Exception - " << e.what() << endl;
        }
    }
    return 0;
}
