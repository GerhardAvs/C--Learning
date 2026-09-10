#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char frase[200];

    cout << "Ingresa una frase: ";
    cin.getline(frase, 200);

    int longitud = strlen(frase);

    // Contar palabras (espacios + 1, si la frase no esta vacia)
    int numPalabras = 0;
    if (longitud > 0) {
        numPalabras = 1;
        for (int i = 0; i < longitud; i++) {
            if (frase[i] == ' ') {
                numPalabras++;
            }
        }
    }

    cout << "Numero de palabras: " << numPalabras << endl;


    return 0;
}