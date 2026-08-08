#include <iostream> //Entrada y salida en C++
#include <stdlib.h>//nos comunicamos con el Sistema Operativo para reiniciar la pantalla
#include <iomanip>
#include <cstring> // Necesario para strcmp

using namespace std;

//Variable global
int arreglo[10][20]; //Se reservan 200 espacios, es decir, requiere 800 Bytes en RAM

int main()
{
    /*int *ptr; Solo guarda direcciones en ram, consume direcciones en 4 bytes
    Pueden ser de tipo int, char, arreglo, a través de un puntero puedo acceder a cierta memoria ram
    IMPORTANTE: se utiliza free en conjunto a malloc */
    int *ptr = (int*)malloc(800); /* Funcion de C, Memory a location. Se esá guardando 800 Bytes. Malloc regresa direcciones de tipo void
                               (int*)malloc(800) es el casting de malloc a type int, void => int */
    int *ptr2 = ptr; // Apuntador auxiliar(ptr2)
    /*
    Memory leak (fuga de memoria): Cuando se usa memoria RAM y al finalizar el programa no se libera

    Stack overflow: El programa se divide en: Código,Pila,Datos, El SO da un espacio de memoria llamado Hip Memory.
                    Cada que se llaman funciones, se inicializan o crean datos, se va llenando la pila, cuando se meten tantos 
                    datos o hay recursividad y no se determina el fin que llenan la pila se llama stack overflow
    */
        for (int i = 1; i <= 200; i++){
           *ptr2 = i; // Apunta al valor inicial y se mueve de 1 en 1, guardando los valores de i hacia las posiciones que apunta el puntero
           ptr2++; // Se mueve de dirección, ejemplo: de la posicion 0, se mueve 4 bytes en ram a la posicion 1
        }

    ptr2 = ptr; //Se resetea el apuntador a la posicion inicial

        for(int i = 1; i <= 200; i++){
            cout << *ptr<< " "; //Como inicia en 0, imprime desde la primera posición hasta la 200
            ptr++; // Se mueve de espacio para que al ejecutar otra vez, se tome el valor siguiente
        }
    
    free(ptr); // Se libera el valor en RAM que almacenamos
    return 0;
}
    /*
    const int fila = 10;
    const int columna = 20;

    cout << "Dame las filas que necesitas: "<<endl;
    cin >> fila; No se pueden modificar constantes

    cout << "Dame las filas que necesitas: "<<endl;
    cin >> columna; No se pueden modificar constantes
    
    int arreglo[fila][columna];*/
