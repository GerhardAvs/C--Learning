#ifndef NODE_H
#define NODE_H

/**
 * @brief Represents a node in a singly linked list.
 * 
 * This structure stores a data element and a pointer
 * to the next node in the list.
 * 
 * @tparam T Data type stored in the node.
 */
template<class T>
struct Node{

private:
    T data;              ///< Value stored in the node
    Node<T>* next;       ///< Pointer to the next node

public:

    /**
     * @brief Constructs a new Node object.
     * 
     * Initializes the node with a value and sets
     * the next pointer to nullptr.
     * 
     * @param value Value to be stored in the node.
     */
    Node(T value){
        data = value;
        next = nullptr;
    }

    /**
     * @brief Gets the data stored in the node.
     * 
     * @return T Value stored in the node.
     */
    T getData() const {
        return data;
    }

    /**
     * @brief Gets the next node.
     * 
     * @return Node<T>* Pointer to the next node.
     */
    Node<T>* getNext() const {
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