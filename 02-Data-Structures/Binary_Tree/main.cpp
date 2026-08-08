#include <iostream>
#include "binary_tree.h"

int menu();
bool call_functions();



bool run = true;
int opc = 0;

int main(){
    BinaryTree<int> tree;
    while (true){
        switch (menu()){
            case 1:
                tree.insert_data();
                break;
            case 2:
                tree.display_tree();
                break;
            case 3:
                break;
        }
    }
    return 0;
}

int menu(){
    std::cout<<"1- Insertar"<<std::endl;
    std::cout<<"2- Mostrar"<<std::endl;
    std::cout<<"3- Salir"<<std::endl;

    std::cout<<"Ingresa tu opcion: ";
    while(opc < 1 || opc > 3){
        std::cin>>opc;
    }
    return opc;
};
