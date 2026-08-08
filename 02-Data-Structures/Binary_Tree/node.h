#ifndef NODE_H
#define NODE_H

template <class T>
struct Node{
    private:
        T data;
        Node<T>* ref_izq = nullptr;
        Node<T>* ref_der = nullptr;

    public:
        Node(T new_dato): data(new_dato) {}

        T get_data(){
            return data;
        };

        Node<T>* get_izq(){
            return ref_izq;
        };

        Node<T>* get_der(){
            return ref_der;
        };

        void set_data(T new_dato){
            data = new_dato;
        }

        void set_izq(Node<T>* new_izq){
            ref_izq = new_izq;
        };

        void set_der(Node<T>* new_der){
            ref_der = new_der;
        };
};      

#endif