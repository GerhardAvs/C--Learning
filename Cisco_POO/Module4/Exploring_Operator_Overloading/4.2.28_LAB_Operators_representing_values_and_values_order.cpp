#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Seis estados: inicio, dos capas de dos estados intermedios y fin
enum State { START = 1, LAYER1_A, LAYER1_B, LAYER2_A, LAYER2_B, STOP };

class FSM {
public:
    FSM() : current(START) { visited.push_back(START); }

    // Regla: valor < 5 va a un estado, valor >= 5 va a otro
    FSM &operator<<(int value) {
        if (current == STOP)
            return *this;              // ya termino, se ignora

        bool low = value < 5;
        switch (current) {
            case START:    current = low ? LAYER1_B : LAYER1_A; break;
            case LAYER1_A: current = low ? LAYER2_A : LAYER2_B; break;
            case LAYER1_B: current = low ? LAYER2_B : LAYER2_A; break;
            case LAYER2_A:
            case LAYER2_B: current = STOP; break;
            default: break;
        }
        visited.push_back(current);

        if (current == STOP)
            cout << "Stop state reached" << endl;
        return *this;
    }

    bool finished() const { return current == STOP; }

    void printVisited() const {
        cout << "States visited:" << endl;
        for (size_t i = 0; i < visited.size(); i++) {
            if (i) cout << ", ";
            cout << visited[i];
            if (visited[i] == START) cout << "(Start)";
            if (visited[i] == STOP)  cout << "(Stop)";
        }
        cout << endl;
    }

private:
    State current;
    vector<State> visited;
};

int main(void) {
    FSM fsm;
    string line;

    // Acepta lineas tipo "fsm<<3;" o solo el numero
    while (getline(cin, line) && !fsm.finished()) {
        string digits;
        for (char c : line)
            if (c >= '0' && c <= '9')
                digits += c;
        if (!digits.empty())
            fsm << stoi(digits);
    }

    fsm.printVisited();
    return 0;
}
