#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>
#include "Node.h"

using namespace std;

/**
 * @file Stack.h
 * @brief Template class that implements a Stack using a linked list.
 * 
 * @tparam T Data type stored in the stack.
 */
template<typename T>
class Stack{

private:
    Node<T>* top; ///< Pointer to the top element of the stack

public:

    /**
     * @brief Constructor that initializes an empty stack.
     */
    Stack(){
        top = nullptr;
    }

    /**
     * @brief Inserts a new element at the top of the stack.
     * 
     * @param data Value to be inserted.
     */
    void push(T data){
        Node<T>* newNode = new Node<T>(data);

        newNode->setNext(top);
        top = newNode;
    }

    /**
     * @brief Removes and returns the element at the top of the stack.
     * 
     * @return T Value removed from the stack.
     * @throws runtime_error if the stack is empty.
     */
    T pop(){
        if(top == nullptr){
            throw runtime_error("Stack is empty");
        }

        Node<T>* temp = top;
        T data = top->getData();

        top = top->getNext();
        delete temp;

        return data;
    }

    /**
     * @brief Returns the value at the top without removing it.
     * 
     * @return T Value at the top of the stack.
     * @throws runtime_error if the stack is empty.
     */
    T peek(){
        if(top == nullptr){
            throw runtime_error("Stack is empty");
        }

        return top->getData();
    }

    /**
     * @brief Displays all elements in the stack.
     */
    void display(){
        Node<T>* current = top;

        if(top == nullptr){
            cout<<"The stack is empty"<<endl;
        }
        else{
            cout << "Top";

            while(current != nullptr){
                cout << " -> [" << current->getData() << "]";
                current = current->getNext();
            }

            cout << endl;
        }

    }

};

#endif
