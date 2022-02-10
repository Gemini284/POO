#include "MyLinkedList.h"
#include <iostream>
#include <limits>

//
MyLinkedList::MyLinkedList(){
    this->size = 0;
    this->first = this->last = nullptr;
}


int MyLinkedList::length(){
    return this->size;
}

bool MyLinkedList::isEmpty(){
    return this->size == 0;
    if (this->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Complejidad O(1)
void MyLinkedList::insertfirst(string key,int data){
    this->first = new MyNodeLL(key,data,this->first);
    if(this->size == 0){
        this->last = this->first;
    }
    this->size++;    
}

//complejidad O(n)
int MyLinkedList::getAt(string key){
    MyNodeLL* current = this->first;
    for(int i = 0; i<this->size;i++){
        if(current->key == key){
            return current->data;
        }
        current=current->next;
    }
    throw invalid_argument("no se encontro la llave "+key+" en la tabla" );
}

// complejidad O(n)
void MyLinkedList::removeFirst(){
    if (this->size > 0)
    {
        MyNodeLL *tmp = this->first;
        this->first = this->first->next;
        delete tmp;
        if (this->size == 0)
        {
            this->last = nullptr;
        }
    }
    else
    {
        throw invalid_argument("removeFirst: No se puede borrar el primer elemento de una lista vacia");
    }
    this->size--;
}

//complejidad O(log n)
void MyLinkedList::removelast(){
    if (this->size > 0)
    {
        MyNodeLL *tmp = this->first;
        MyNodeLL *current;
        while (tmp->next->next != nullptr)
        { //segundo ultimo nodo
            tmp = tmp->next;
            current = tmp->next;
        }
        tmp->next = nullptr;
        delete (current);
        this->size--;
    }
    else
    {
        throw invalid_argument("No se puede acceder al último elemento");
    }
}

//Funcion que elimina un nodo en una posicion, complejidad O(n)
void MyLinkedList::removeat(int pos){
    if (pos > 0 && pos < this->size){
        MyNodeLL *tmp = this->first;
        MyNodeLL *elimina;
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        elimina = tmp->next;
        tmp->next = elimina->next;
        delete elimina;
    }
    else
    {
        throw invalid_argument("removeAt: No se puede acceder a la posicion " + to_string(pos) + " en una lista de tamaño " + to_string(this->size));
    }
}