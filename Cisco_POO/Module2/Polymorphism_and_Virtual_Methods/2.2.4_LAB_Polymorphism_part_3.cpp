#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class IPAddress {
protected:
    string value;

public:
    IPAddress(const string& ip) : value(ip) {}

    IPAddress(const IPAddress& other) : value(other.value) {}

    string getValue() const { return value; }

    void print() const {
        cout << value << endl;
    }
};

// Devuelve true si el texto tiene formato a.b.c.d con cada octeto entre 0 y 255
bool isValidIP(const string& ip) {
    int parts = 0;
    size_t start = 0;

    while (true) {
        size_t dot = ip.find('.', start);
        string piece = ip.substr(start, dot == string::npos ? string::npos : dot - start);

        if (piece.empty() || piece.size() > 3)
            return false;

        int number = 0;
        for (char c : piece) {
            if (!isdigit(static_cast<unsigned char>(c)))
                return false;
            number = number * 10 + (c - '0');
        }

        if (number > 255)
            return false;

        ++parts;
        if (dot == string::npos)
            break;
        start = dot + 1;
    }

    return parts == 4;
}

class IPAddressChecked : public IPAddress {
private:
    bool correct;

public:
    IPAddressChecked(const string& ip)
        : IPAddress(ip), correct(isValidIP(ip)) {}

    IPAddressChecked(const IPAddressChecked& other)
        : IPAddress(other), correct(other.correct) {}

    void print() const {
        cout << getValue() << " - " << (correct ? "Correct" : "Not Correct") << endl;
    }
};

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    IPAddress ip1(s1);
    IPAddressChecked ip2(s2);
    IPAddressChecked ip3(s3);

    ip1.print();
    ip2.print();
    ip3.print();

    return 0;
}