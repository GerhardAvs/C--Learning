#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "node.h"

template <class T>
class BinaryTree{
    private:
        T dato = 0;
        Node<T>* aux = nullptr;
        Node<T>* aux2 = nullptr;

        Node<T>* root = nullptr;
        
    public: 

void insert_data() {
    T dato;

    std::cout << "Ingresa el dato: " << std::endl;
    std::cin >> dato;

    if (root == nullptr) {
        root = new Node(dato);
    }
    else {
        aux = root;

        while (aux != nullptr) {

            if (dato < aux->get_data()) {

                if (aux->get_izq() == nullptr) {
                    aux->set_izq(new Node(dato));
                    break;
                }
                else {
                    aux = aux->get_izq();
                }

            }
            else if (dato > aux->get_data()) {

                if (aux->get_der() == nullptr) {
                    aux->set_der(new Node(dato));
                    break;
                }
                else {
                    aux = aux->get_der();
                }

            }
            else {
                std::cout << "El dato ya existe." << std::endl;
                break;
            }
        }
    }
}
        void display_tree(){
            aux = aux2 = root;
            
            std::cout<<aux->get_data()<<std::endl;
            aux = aux->get_der();
            aux2 = aux2->get_izq();
            std::cout<<aux->get_data()<<"     "<<aux->get_data()<<std::endl;

        }

        void delete_data(){

        }
        
        T search(){

        }

        void inorder(){

        };

        void preorder(){

        };

        void postorder(){

        };
};

#endif