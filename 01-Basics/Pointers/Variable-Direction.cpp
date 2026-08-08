#include <iostream> //Entrada y salida en C++
#include <stdlib.h>//nos comunicamos con el Sistema Operativo para reiniciar la pantalla
#include <iomanip>
#include <cstring> // Necesario para strcmp

using namespace std;

int main(){
    int x = 10; //Variable entera x igual a 10
    int *ptr; //Se inicializa el puntero

    ptr = &x; //Guarda la direccion en la que se guardo x

    cout<<*ptr<<endl; //Se imprime hacia a donde apunta el puntero
    return 0;
}
