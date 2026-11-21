#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

// La excepcion lleva la informacion de que IP esta mal
class InvalidIPHeader : public runtime_error {
public:
    InvalidIPHeader(const string &info) : runtime_error("Invalid IP Header - " + info) {}
};

struct IPHeader {
    string sourceIP;
    string destinationIP;

    // Una sola version: el constructor solo llama a check()
    IPHeader(const string &source, const string &destination)
        : sourceIP(source), destinationIP(destination) {
        check();
    }

    // Revisa ambas direcciones y lanza la excepcion con el detalle
    void check() const {
        bool sourceOk = isValidIP(sourceIP);
        bool destinationOk = isValidIP(destinationIP);

        if (!sourceOk && !destinationOk)
            throw InvalidIPHeader("Source and Destination IP Addresses are invalid.");
        if (!sourceOk)
            throw InvalidIPHeader("Source IP Address is invalid.");
        if (!destinationOk)
            throw InvalidIPHeader("Destination IP Address is invalid.");
    }

    // 4 numeros de 0 a 255 separados por punto
    static bool isValidIP(const string &ip) {
        stringstream ss(ip);
        string part;
        int count = 0;
        while (getline(ss, part, '.')) {
            if (part.empty() || part.size() > 3)
                return false;
            for (char c : part)
                if (c < '0' || c > '9')
                    return false;
            if (stoi(part) > 255)
                return false;
            count++;
        }
        return count == 4 && ip.back() != '.';
    }
};

int main(void) {
    string source, destination;

    // pares de lineas: IP origen, IP destino
    while (cin >> source >> destination) {
        try {
            IPHeader header(source, destination);
            cout << "Valid IP Header." << endl;
        }
        catch (InvalidIPHeader &e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
