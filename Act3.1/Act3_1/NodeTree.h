#ifndef _NODE_BST_H_
#define _NODE_BST_H_

#include<iostream>

template <class T>
class NodeTree { 
public: 
    T data; 
    NodeTree<T>* left;
    NodeTree<T>* right;
    NodeTree();
    NodeTree(T, int);
    int getAltura();
    void setAltura(int);
private:
    int altura;  
}; 

template<class T>
NodeTree<T>::NodeTree(){
    left = NULL;
    right = NULL;
    altura = 0;
}

template<class T>
NodeTree<T>::NodeTree(T val, int alt){
    data = val;
    left = NULL;
    right = NULL;
    altura = alt;
}

template<class T>
int NodeTree<T>::getAltura(){
return altura;
}

template<class T>  
void NodeTree<T>:: setAltura(int alt){
altura = alt;
}

#endif // _NODE_BST_H_