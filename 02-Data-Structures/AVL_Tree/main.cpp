#include <iostream>
#include "AVL.h"

using namespace std;

int menu();

int main(){

    AVL tree;
    int option, value;

    do{
        option = menu();

        switch(option){

            case 1:
                cout << "Ingrese valor: ";
                cin >> value;

                tree.insertValue(value);
                cout << "Valor insertado correctamente.\n";
                break;

            case 2:
                tree.displayInorder();
                break;

            case 3:
                cout << "Altura del arbol AVL: "
                     << tree.getTreeHeight() << endl;
                break;

            case 4:{   // <-- llaves aquí
                cout << "\nPrueba automatica (1,2,3,4,5)\n";

                AVL testTree;

                testTree.insertValue(1);
                testTree.insertValue(2);
                testTree.insertValue(3);
                testTree.insertValue(4);
                testTree.insertValue(5);

                testTree.displayInorder();

                cout << "Altura final: "
                     << testTree.getTreeHeight() << endl;

                cout << "Aqui se observa como AVL evita convertirse en lista.\n";
                break;
            }

            case 5:
                cout << "Saliendo...\n";
                break;
        }

    }while(option != 5);

    return 0;
}

int menu(){

    int option;

    do{
        cout << "\n======= MENU AVL =======\n";
        cout << "1. Insertar valor\n";
        cout << "2. Mostrar Inorden\n";
        cout << "3. Mostrar altura\n";
        cout << "4. Prueba ascendente (1,2,3,4,5)\n";
        cout << "5. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> option;

    }while(option < 1 || option > 5);

    return option;
}