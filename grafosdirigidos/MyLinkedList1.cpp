//
//  main.cpp
//  ListaEnlazada
//
//  Created by Manuel Cardenas on 24/09/21.
//

#include <iostream>
#include "MyLinkedList.h"
#include <limits>
using namespace std;

MyLinkedList::MyLinkedList(){
    this->size = 0;
    this->head = this->tail = nullptr;
}

//Complejidad: O(1)
int MyLinkedList::length(){
    return this->size;
}

//Complejidad: O(1)
void MyLinkedList::insertFirst(string key, int data){
    MyNodeLL* nuevoNodo=new MyNodeLL(key, data);
    nuevoNodo->next = this->head;
    this->head = nuevoNodo;
    this->size++;
}

//Complejidad: O(1)
void MyLinkedList::removeFirst(){
    MyNodeLL* tmp = this->head;
    if (this->head == nullptr){
        cout << "La lista esta vacía, no se puede eliminar nada" << endl;
    }
    else{
        this->head = this->head->next;
        delete(tmp);
        this->size--;
    }
}

//Complejidad: O(1)
void MyLinkedList::removeLast(){
    if (this->size>0){
        MyNodeLL* tmp = this->tail;
        this->tail = this->tail->next;
        delete(tmp);
        this->size--;
    }
    else{
        throw invalid_argument("No se puede borrar porque la lista esta vacía");
    }
}

//Complejidad: O(n)
int MyLinkedList::getAt(string key){
    MyNodeLL* current = this->head;
    for(int i=0; i<this->size; i++){
        if(current->key == key){
            return current->data;
        }
        current = current->next;
    }
    throw invalid_argument("No se encontró la llave: " + key);
}

//Complejidad: O(1)
bool MyLinkedList::isEmpty(){
    return this->size == 0;
}

//Complejidad: O(n)
void MyLinkedList::quitar(string key){
    MyNodeLL* current = this->head;
    if (current->key == key){ //Caso base....
        this->head = this->head->next;
        delete(current);
    }
    while(current->key != key){
        current = current->next;
    }
    if(current == nullptr){
        cout << "No se encontro la key en la tabla" << endl;
    }
    else{
        delete(current);
        this->size--;
    }
}
