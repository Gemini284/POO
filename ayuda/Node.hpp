#ifndef _NODE_HPP_
#define _NODE_HPP_

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
    
    /*Lidear con los diferentes tipos de información me resulto tedioso, 
     *pues múltiples errores pueden ocurrir al utilizar una clase dentro
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

#endif // _NODE_HPP_