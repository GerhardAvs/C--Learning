#ifndef AVL_H
#define AVL_H

#include "Node.h"
#include <iostream>
using namespace std;

class AVL{
private:
    Node* root;

    // Obtener altura
    int getHeight(Node* node){
        if(node == nullptr){
            return 0;
        }
        return node->height;
    }

    // Obtener máximo
    int getMax(int a, int b){
        return (a > b) ? a : b;
    }

    // Factor de balance
    int getBalance(Node* node){
        if(node == nullptr){
            return 0;
        }

        return getHeight(node->left) - getHeight(node->right);
    }

    //-----------------------------------
    // ROTACION SIMPLE DERECHA (LL)
    //-----------------------------------
    Node* rotateRight(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    //-----------------------------------
    // ROTACION SIMPLE IZQUIERDA (RR)
    //-----------------------------------
    Node* rotateLeft(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    //-----------------------------------
    // INSERTAR
    //-----------------------------------
    Node* insert(Node* node, int value){

        // Inserción normal de ABB
        if(node == nullptr){
            return new Node(value);
        }

        if(value < node->data){
            node->left = insert(node->left, value);
        }
        else if(value > node->data){
            node->right = insert(node->right, value);
        }
        else{
            return node;
        }

        // Actualizar altura
        node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));

        // Revisar balance
        int balance = getBalance(node);

        // CASO LL
        if(balance > 1 && value < node->left->data){
            return rotateRight(node);
        }

        // CASO RR
        if(balance < -1 && value > node->right->data){
            return rotateLeft(node);
        }

        // CASO LR
        if(balance > 1 && value > node->left->data){
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // CASO RL
        if(balance < -1 && value < node->right->data){
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    //-----------------------------------
    // RECORRIDO INORDEN
    //-----------------------------------
    void inorder(Node* node){
        if(node != nullptr){
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    AVL(){
        root = nullptr;
    }

    void insertValue(int value){
        root = insert(root, value);
    }

    void displayInorder(){
        cout << "Recorrido Inorden: ";
        inorder(root);
        cout << endl;
    }

    int getTreeHeight(){
        return getHeight(root);
    }
};

#endif