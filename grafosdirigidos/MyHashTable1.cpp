//
//  MyHashTable.cpp
//  Hashing
//
//  Created by Manuel Cardenas on 24/11/21.
//

#include "MyHashTable.h"
#include "MyLinkedList.h"

MyHashTable::MyHashTable(){
    this->size = 0;
    this->sizeA = 11;
    this->tabla = new MyLinkedList[this->sizeA];
}

//Complejidad: O(n)
MyHashTable::~MyHashTable(){
    for(int i=0; i<= this->sizeA; i++){
        this->tabla[i].~MyLinkedList();
    }
    delete[] this->tabla;
}

//Complejidad: O(1)
bool MyHashTable::isEmpty(){
    return this->size == 0;
}

//Complejidad: O(n)
int MyHashTable::getPos(string key){
    size_t hashC = hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}

//Complejidad: O(1)
void MyHashTable::put(string key, int value){
    int pos = getPos(key);
    this->tabla[pos].insertFirst(key, value);
    this->size++;
}

//Complejidad: O(n)
int MyHashTable::get(string key){
    int pos = getPos(key);
    MyLinkedList* lista = &this->tabla[pos];
    return lista->getAt(key);
}

//Complejidad: O(1)
void MyHashTable::remove(string key){
    MyLinkedList val;
    val.quitar(key);
}

void MyHashTable::rehashing(){
    
}
