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

    // Contar vocales
    int numVocales = 0;
    for (int i = 0; i < longitud; i++) {
        char c = tolower(frase[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            numVocales++;
        }
    }

    // Invertir la frase
    char invertida[200];
    for (int i = 0; i < longitud; i++) {
        invertida[i] = frase[longitud - 1 - i];
    }
    invertida[longitud] = '\0';

    cout << "Numero de palabras: " << numPalabras << endl;
    cout << "Numero de vocales: " << numVocales << endl;
    cout << "Frase invertida: " << invertida << endl;

    return 0;
}