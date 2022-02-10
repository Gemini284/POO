#ifndef _BinarySearchTree_H_
#define _BinarySearchTree_H_

#include<iostream>
#include "NodeTree.h"

template <class T>
class BinarySearchTree { 
    private:
        //Metodos
        NodeTree<T> *root;
        NodeTree<T>* insertRecursive(NodeTree<T> *p, T value);
        NodeTree<T>* getSuccessor(NodeTree<T> *p);
        NodeTree<T>* deleteRecursive(NodeTree<T> *p, T value);
        void inorder(NodeTree<T> *p);
        void postorder(NodeTree<T> *p);
        void preorder(NodeTree<T> *p);
        void setalturas(NodeTree<T> *p);
        void levelbylevel(NodeTree<T> *p, int i);
        void whatLevel(NodeTree<T> *p, T value);
        void ancestors(NodeTree<T> *p, T value);
        //Atributos
        int niveles;
        int alturaNodo;
        

    public: 
        //Constructor por default
        BinarySearchTree();
        //Destructor
        ~BinarySearchTree();

        //Metodos
        void clearMemory(NodeTree<T> *p);
        void insert(T value);
        bool search(T value);
        void deleteNode(T value);
        void callInorder();
        void callPostorder();
        void callPreorder();
        void callLevel(int n);
        int getHigh();
        void callAncestors(T value);
        int callwhatLevel(T value);
        void visit(int m);
        NodeTree<T>* getLastNode();
}; 

template<class T>
BinarySearchTree<T>::BinarySearchTree() {
    std::cout << "--->Creando un BinarySearchTree vacio: " <<  this << std::endl;
    root = NULL;
    niveles = 0;
    alturaNodo = 0;
}
  
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    std::cout << "--->Liberando memoria del BinarySearchTree: " << this << std::endl;
    clearMemory(root);
}

template<class T>
void BinarySearchTree<T>::clearMemory(NodeTree<T> *p) {
    if (p != NULL) {
        clearMemory(p->left);
        clearMemory(p->right);
        delete p;
        p = NULL;
    }
}


template<class T>
NodeTree<T>* BinarySearchTree<T>::insertRecursive(NodeTree<T> *p, T value) {
    if (p == NULL){
        p = new NodeTree<T>(value,0);
    }
    else if (value < p->data){
        p->left = insertRecursive(p->left, value);
    }
    else if (value > p->data){
        p->right = insertRecursive(p->right, value);
    }
    else{
        std::cout << "El elemento " << value << " ya existe en el BST" << std::endl;
    }
    return p;
}


template<class T>
void BinarySearchTree<T>::insert(T value) {
    root = insertRecursive(root, value);
}

template<class T>
bool BinarySearchTree<T>::search(T value) {
    NodeTree<T> *p = root;
    while (p != NULL) {
        if (p->data == value) {
        return true;
        }
        else {
        p = (value < p->data ? p->left : p->right);
        }
    }
    return false;
}

template<class T>
NodeTree<T> * BinarySearchTree<T>::getSuccessor(NodeTree<T> *p) {
    NodeTree<T> *current = p;
    while (current && current->left != NULL) {
      current = current->left;
    }
    return current;
}

template<class T>
void BinarySearchTree<T>::deleteNode(T value) {
    root = deleteRecursive(root, value);
}

template<class T> 
NodeTree<T>* BinarySearchTree<T>::deleteRecursive(NodeTree<T> *p, T value) {
    NodeTree<T> *current = p;
    // caso base 
    if (p == NULL)
        return p;
    if (value < p->data)
        p->left = deleteRecursive(p->left, value);
    else if (value > p->data)
        p->right = deleteRecursive(p->right, value);
    else { // Hemos localizado el nodo a borrar
        // El nodo a borrar no tiene ningun hijo
        if (p->left == NULL && p->right == NULL) {
        delete p;
        p = NULL;
        return p;
        }
        else if (p->left == NULL) { // El nodo a borrar solo tiene hijo derecho
        current = p->right;
        delete p;
        p = NULL;
        return current;
        } 
        else if (p->right == NULL) { // El nodo a borrar solo tiene hijo izquierdo
        current = p->left;
        delete p;
        p = NULL;
        return current;
        }
        // El nodo a borrar tiene dos hijos
        current = getSuccessor(p->right);
        p->data = current->data;
        p->right = deleteRecursive(p->right, current->data);
    }
    return p;
}
//Funcion para imprimir el arbol binario en modo inorder
//Complejidad de la funcion: O(n)
template<class T>
void BinarySearchTree<T>::inorder(NodeTree<T> *p) {
    if (p != NULL) {
        inorder(p->left);
        std::cout << p->data << " ";
        inorder(p->right);
    }
}

//Funcion para mandar a llamar al metodo inorder
//Complejidad de la funcion: O(1)
template<class T>
void BinarySearchTree<T>::callInorder() {
    std::cout << "\nRecorrido inorder" << std::endl;
    inorder(root);
    std::cout << std::endl;
}

//Funcion para imprimir el arbol binario en modo postorder
//Complejidad de la funcion: O(n)
template<class T>
void BinarySearchTree<T>::postorder(NodeTree<T> *p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        std::cout << p->data << " ";
    }
}

//Funcion para mandar a llamar el postorder
//Complejidad de la funcion: O(1)
template<class T>
void BinarySearchTree<T>::callPostorder() {
    std::cout << "\nRecorrido postorder" << std::endl;
    postorder(root);
    std::cout << std::endl;
}

//Funcion para imprimir el arbol binario en modo preorder
//Complejidad de la funcion: O(n)
template<class T>
void BinarySearchTree<T>::preorder(NodeTree<T> *p) {
    if (p != NULL) {
        std::cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

//Funcion para mandar a llamar el preorder
//Complejidad de la funcion: O(1)
template<class T>
void BinarySearchTree<T>::callPreorder() {
    std::cout << "\nRecorrido preorder" << std::endl;
    preorder(root);
    std::cout << std::endl;
}

//-->Funciones de la act 3.1

//Funcion para asignarle su altura a un nodo del arbol
//Complejidad de la funcion O(n) o tambien O(2^n)
template<class T>
void BinarySearchTree<T>::setalturas(NodeTree<T> *p) {
    if (p != NULL) {
        setalturas(p->left);
        p->setAltura(callwhatLevel(p->data));
        niveles++;
        setalturas(p->right);
    };
}


//Funcion para recorrer el arbol nivel por nivel
//Complejidad de la funcion: O(n) o O(2^n)
template<class T>
void BinarySearchTree<T>::levelbylevel(NodeTree<T> *p, int i) {
    if (p != NULL) {
        if ( p->left != NULL && p->left->getAltura() == i ){
            std::cout << p->left->data << " ";
        }
        if (p->right !=NULL && p->right->getAltura() == i ){
            std::cout << p->right->data << " ";
        }
        levelbylevel(p->left, i);
        levelbylevel(p->right, i);
  }
}
  
//Funcion para mandar a llamar el level by level
//Complejidad de la funcion: O(1)
template<class T>
void BinarySearchTree<T>::callLevel( int n) {
    std::cout<< "\nRecorrido por nivel"<<std::endl;
    NodeTree<T> *p = root;
    niveles = 0;
    setalturas(p);
    std::cout<< p->data<< " ";
    for (int i = 1; i<= niveles; i++){
        levelbylevel(p,i);
    } 
    std::cout<<""<<std::endl;
}   

//Funcion para obtener la altura del arbol
//Complejidad de la funcion: O(1)
template<class T>
int BinarySearchTree<T>::getHigh() {
    NodeTree<T> *p = root;
    niveles = 0;
    setalturas(p);
    return (niveles-1)/2;
}

//Funcion para encontrar los ancestros de un valor especifico
//Complejidad de la funcion: O(n)
template<class T>
void BinarySearchTree<T>::ancestors(NodeTree<T> *p, T value) {
    //El arbol esta vacio
    if (p == NULL){
        std::cout<< "-1";
        niveles = 0;
    }
    //El dato se busca para la izquierda
    else if (value < p->data){
      p = p->left;
      ancestors(p, value);
      
    }
    //El dato se busca para la derecha
    else if (value > p->data){
      p = p->right;
      ancestors(p, value);
    }
    //Se imprimen los ancestros
    if ( p != NULL && value != p->data && niveles != 0){
        std::cout<<p->data<< " ";        
    }  
}


//Funcion para mandar a llamar a ancestors
//Complejidad de la funcion: O(1)
template<class T>
void BinarySearchTree<T>::callAncestors(T value){
    NodeTree<T> *p = root;
    //El arbol no esta vacio
    if (p!= NULL){
        ancestors(p, value);
        if ( niveles != 0){
        std::cout<<p->data<<std::endl;
        }
    }
    //El arbol esta vacio   
    else{
      std::cout<<"-1"<<std::endl;
    }
}

//Funcion que te dice en que nivel del arbol esta el valor ingresado
//Complejidad de la funcion: O(n)
template<class T> 
void BinarySearchTree<T>::whatLevel(NodeTree<T> *p, T value) {
    //El arbol esta vacio
    if (p == NULL){
      alturaNodo = -1;
    }
    //El dato va hacia la izquierda
    else if (value < p->data){
      alturaNodo ++;
      p = p->left;
      whatLevel(p, value);
    }
    //El dato va hacia la derecha
    else if (value > p->data){
        alturaNodo++;
        p = p->right;
        whatLevel(p, value);
    }
}

//Funcion para mandar a llamar el What level am I
//Complejidad de la funcion: O(1)
template<class T>
int BinarySearchTree<T>::callwhatLevel(T value) {
    NodeTree<T> *p = root;
    //El arbol no esta vacio
    if (p!= NULL){
        alturaNodo = 1; 
        whatLevel(p, value);
    }
    //El arbol esta vacio
    else{
        alturaNodo = -1;
    } 
    return alturaNodo;
}

//Funcion que sirve como un menu para elegir que recorrido al arbol utilizar
//Complejidad de la funcion: O(1)
template<class T>
void BinarySearchTree<T>::visit(int m){
  if (1<= m <= 4){
    if(m == 1){
      callPreorder();
    }
    else if(m ==2 ){
      callInorder();
    }
    else if(m == 3){
      callPostorder();
    }
    else{
      callLevel(1);
    }
  }
}

#endif // _BinarySearchTree_H_