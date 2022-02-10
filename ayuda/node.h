#ifndef NODE_H
#define NODE_H

    #include<iostream>

    template <class T>
    class Node { 
    public: 
        T data; 
        Node<T>* next;
        Node<T>* prev;
        Node();
        Node(const T &val);
        Node (const Node<T>&);
    }; 
    
    /*al utilizar una clase dentro de un template pueden salir varios errores, así que se me ocurrio esto
     * de un template*/
    template<class T>
    Node<T>::Node(){
        data = NULL;
        next = NULL;
        prev = NULL;
    }
    template<class T>
    Node<T>::Node(const T &val){
        data = val;
        next = NULL;
        prev = NULL;
    }
    template<class T>
    Node<T>::Node(const Node<T> &val) {
        data = val.data;
        next = val.next;
        prev = val.prev;
    }

#endif 