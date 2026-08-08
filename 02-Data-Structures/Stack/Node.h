#ifndef NODE_H
#define NODE_H

/**
 * @file Node.h
 * @brief Definition of the Node structure used in linked data structures.
 * 
 * @tparam T Data type stored in the node.
 */

template<typename T>
struct Node{

private:
    T data;        ///< Value stored in the node
    Node<T>* next; ///< Pointer to the next node

public:

    /**
     * @brief Constructor that initializes the node with a value.
     * 
     * @param value Value to be stored in the node.
     */
    Node(T value){
        data = value;
        next = nullptr;
    }

    /**
     * @brief Returns the stored value.
     * 
     * @return T Data stored in the node.
     */
    T getData(){
        return data;
    }

    /**
     * @brief Returns the next node pointer.
     * 
     * @return Node<T>* Pointer to the next node.
     */
    Node<T>* getNext(){
        return next;
    }

    /**
     * @brief Sets the next node pointer.
     * 
     * @param newNext Pointer to the next node.
     */
    void setNext(Node<T>* newNext){
        next = newNext;
    }

};

#endif
