#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * @brief Template class that implements a Queue using a linked list.
 * 
 * @tparam T Type of data stored in the queue.
 */
template<class T>
class Queue{

private:
    Node<T>* head; ///< Pointer to the first element of the queue
    Node<T>* tail; ///< Pointer to the last element of the queue

public:

    /**
     * @brief Constructor that initializes an empty queue.
     */
    Queue(){
        head = nullptr;
        tail = nullptr;
    }

    /**
     * @brief Inserts a new element at the end of the queue.
     * 
     * @param data Value to be inserted.
     */
    void enqueue(T data){
        Node<T>* newNode = new Node<T>(data);

        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail->setNext(newNode);
            tail = newNode;
        }
    }

    /**
     * @brief Removes and returns the first element of the queue.
     * 
     * @return T Value removed from the queue.
     * @throws runtime_error if the queue is empty.
     */
    T dequeue(){
        if(head == nullptr){
            throw runtime_error("Queue is empty");
        }

        Node<T>* temp = head;
        T data = head->getData();

        head = head->getNext();
        delete temp;

        return data;
    }

    /**
     * @brief Returns the first element of the queue without removing it.
     * 
     * @return T First element in the queue.
     * @throws runtime_error if the queue is empty.
     */
    T peek(){
        if(head == nullptr){
            throw runtime_error("Queue is empty");
        }

        return head->getData();
    }

    /**
     * @brief Displays all elements in the queue.
     */
    void display(){
        Node<T>* current = head;

        cout << "Head";

        while(current != nullptr){
            cout << " -> [" << current->getData() << "]";
            current = current->getNext();
        }

        cout << " <- Tail" << endl;
    }

};

#endif
