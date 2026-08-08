#include <iostream>
#include <clocale>
#include <Windows.h>

#define TAM 1
using namespace std;

struct persona
{
    char nombre[20];
    char apellido[30];
    char telefono[11];
    int edad;
    char sexo[1];
    int presionArterial[2];
};
//const int TAM = 10;
struct persona arreglo[TAM] = { "Jose","Prado", "9931234567", 23,'M', 80, 120};

int main(){
    cout<<arreglo[0].nombre<<endl;
    cout<<arreglo[0].apellido<<endl;
    cout<<arreglo[0].telefono<<endl;
    cout<<arreglo[0].edad<<endl;
    cout<<arreglo[0].sexo<<endl;
    cout<<arreglo[0].presionArterial[0]<<endl;
    cout<<arreglo[0].presionArterial[1]<<endl;
    return 0;
}
