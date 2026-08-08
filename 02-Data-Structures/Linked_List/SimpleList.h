#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include <iostream>
#include "Node.h"

using namespace std;

/**
 * @brief Represents a singly linked list.
 * 
 * Provides operations such as insertion, deletion,
 * search, and display of elements.
 * 
 * @tparam T Data type stored in the list.
 */
template<class T>
class SimpleList{

private:
    Node<T>* head; ///< Pointer to the first node
    Node<T>* tail; ///< Pointer to the last node

public:

    /**
     * @brief Constructs an empty list.
     */
    SimpleList(){
        head = nullptr;
        tail = nullptr;
    }

    /**
     * @brief Initializes the list or inserts the first element.
     * 
     * If the list is empty, it sets the first node.
     * Otherwise, it appends the value at the end.
     * 
     * @param value Value to insert.
     */
    void crearlista(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->setNext(newNode);
            tail = newNode;
        }
    }

    /**
     * @brief Inserts a value in ascending order.
     * 
     * @param value Value to insert.
     */
    void AgregarAscendente(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        if (value < head->getData()) {
            newNode->setNext(head);
            head = newNode;
            return;
        }

        Node<T>* current = head;

        while (current->getNext() != nullptr &&
               current->getNext()->getData() < value) {
            current = current->getNext();
        }

        newNode->setNext(current->getNext());
        current->setNext(newNode);

        if (newNode->getNext() == nullptr) {
            tail = newNode;
        }
    }

    /**
     * @brief Deletes a value from the list.
     * 
     * @param value Value to remove.
     */
    void EliminarNumero(T value) {
        if (head == nullptr) return;

        if (head->getData() == value) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;

            if (head == nullptr) {
                tail = nullptr;
            }
            return;
        }

        Node<T>* current = head;

        while (current->getNext() != nullptr &&
               current->getNext()->getData() != value) {
            current = current->getNext();
        }

        if (current->getNext() != nullptr) {
            Node<T>* temp = current->getNext();
            current->setNext(temp->getNext());

            if (temp == tail) {
                tail = current;
            }

            delete temp;
        }
    }

    /**
     * @brief Searches for a value in the list.
     * 
     * @param value Value to search.
     */
    void BuscarNumero(T value) {
        Node<T>* current = head;

        while (current != nullptr) {
            if (current->getData() == value) {
                cout << "Value found\n";
                return;
            }
            current = current->getNext();
        }

        cout << "Value not found\n";
    }

    /**
     * @brief Displays all elements in the list.
     */
/**
 * @brief Displays all elements, total count, and HEAD/TAIL values.
 */
void Desplegar() {
    Node<T>* current = head;
    int count = 0;

    cout << "HEAD -> ";

    while (current != nullptr) {
        cout << "[" << current->getData() << "] -> ";
        current = current->getNext();
        count++;
    }

    cout << "<- TAIL\n";

    // Mostrar cantidad de nodos
    cout << "Total nodes: " << count << endl;

    // Mostrar HEAD
    if (head != nullptr)
        cout << "HEAD value: " << head->getData() << endl;
    else
        cout << "HEAD value: NULL" << endl;

    // Mostrar TAIL
    if (tail != nullptr)
        cout << "TAIL value: " << tail->getData() << endl;
    else
        cout << "TAIL value: NULL" << endl;
    }   

    /**
     * @brief Deletes all elements in the list.
     * 
     * Frees allocated memory.
     */
    void Salir() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }

        tail = nullptr;
        cout << "List cleared successfully\n";
    }
};

#endif