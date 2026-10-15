#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IPAddress {
public:
    IPAddress(const string &ip) : value(ip) {}
    string getValue() const { return value; }
private:
    string value;
};

class Network {
public:
    Network(const string &name) : name(name) {}

    void addAddress(const IPAddress &ip) {
        addresses.push_back(ip);
    }

    void print() const {
        cout << name << ":\n";
        for (const IPAddress &ip : addresses)
            cout << ip.getValue() << "\n";
    }

private:
    string name;
    vector<IPAddress> addresses;
};

int main() {
    string s[5];
    for (int i = 0; i < 5; i++)
        cin >> s[i];

    IPAddress ip1(s[0]), ip2(s[1]), ip3(s[2]), ip4(s[3]), ip5(s[4]);

    Network net1("Network 1");
    Network net2("Network 2");

    net1.addAddress(ip1);
    net1.addAddress(ip2);
    net1.addAddress(ip3);

    net2.addAddress(ip3);   // la misma IP en ambas redes
    net2.addAddress(ip4);
    net2.addAddress(ip5);

    net1.print();
    net2.print();

    return 0;
}