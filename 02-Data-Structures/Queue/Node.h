#ifndef NODE_H
#define NODE_H

/**
 * @brief Template structure that represents a node in a linked list.
 * 
 * @tparam T Data type stored in the node.
 */
template<class T>
struct Node{
    
private:
    T data;           ///< Value stored in the node
    Node<T>* next;    ///< Pointer to the next node in the list

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
     * @brief Returns the data stored in the node.
     * 
     * @return T Data contained in the node.
     */
    T getData(){
        return data;
    }

    /**
     * @brief Returns the pointer to the next node.
     * 
     * @return Node<T>* Pointer to the next node.
     */
    Node<T>* getNext(){
        return next;
    }

    /**
     * @brief Sets the reference to the next node.
     * 
     * @param newNext Pointer to the next node.
     */
    void setNext(Node<T>* newNext){
        next = newNext;
    }
};

#endif
