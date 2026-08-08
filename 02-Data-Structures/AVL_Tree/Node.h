#ifndef NODE_H
#define NODE_H

class Node{
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

#endif