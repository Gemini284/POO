//
//  MyLinkedList.cpp
//  Proyecto2
//
//  Created by Manuel Cardenas on 10/10/21.
//

#include <iostream>
#include <limits>
using namespace std;

#include "Acceso.h"
#include "MyLinkedList.h"

//Constructor por default
MyLinkedList::MyLinkedList(){
    this->head = this->tail = nullptr;
    this->size = 0;
}

int MyLinkedList::length(){
    return this->size;
}

void MyLinkedList::insertFirst(Acceso dato){
    this->head = new MyNodeLL(dato);
    if (this->size == 0){
        this->tail = this->head;
    }
    this->size++;
}

void MyLinkedList::insertLast(Acceso dato){
    MyNodeLL *node = new MyNodeLL(dato);
    if (this->size == 0){
        this->head = node;
        this->tail = this->head;
    }else{
        this->tail->next = node;
        node->prev = this->tail;
        this->tail = node;
    }
    this->size++;
}

Acceso MyLinkedList::getAt(int pos){
    if(pos>=0 && pos<this->size){
        MyNodeLL *current = this->head;
        for (int i = 0; i<pos ; i++){
            current = current->next;
        }
        return current->dato;
    }
    else{
        throw invalid_argument("No se puede acceder a la posición " + to_string(pos) + " en una lista de tamaño " + to_string(this->size));
    }
}

bool MyLinkedList::isEmpty(){
    return this->size == 0;
}

void MyLinkedList::imprimeLista(){
    MyNodeLL *current = this->head;
    for(int i=0; i < this->size; i++){
        current->dato.imprime();
        current = current->next;
    }
}

void MyLinkedList::intercambio(MyNodeLL *A, MyNodeLL *B){
    Acceso temp = A->dato;
    A->dato = B->dato;
    B->dato = temp;
}

bool MyLinkedList::comparaMayorIpPuerto(MyNodeLL*A, MyNodeLL*B){
    if(A->dato.getIpA() == B->dato.getIpA()){
        if (A->dato.getIpB() == B->dato.getIpB()){
            if(A->dato.getIpC() == B->dato.getIpC()){
                if (A->dato.getIpD() == B->dato.getIpD()){
                    return A->dato.getPuerto() > B->dato.getPuerto();
                }else{
                    return A->dato.getIpD() > B->dato.getIpD();
                }
            }else{
                return A->dato.getIpC() > B->dato.getIpC();
            }
        }else{
            return A->dato.getIpB() > B->dato.getIpB();
        }
    }else{
        return A->dato.getIpA() > B->dato.getIpA();
    }
}

void MyLinkedList::ordena(){
    if (this->size > 1){
        cout << "Tam: " << this->size << endl;
        for(int i = 0; i < this->size; i++){
        MyNodeLL *current = this->head,
                 *follow = this->head->next;
            for (int j = 0; j < this->size-1-i; j++){
                if(comparaMayorIpPuerto(current, follow)){
                    intercambio(follow, current);
                }
                current = current->next;
                follow = current->next;
            }
        }
    }
}



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


