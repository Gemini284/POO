//Sofia del Pilar Batiz Martinez A01634125
#include "MyHashTable.h"
#include "MyLinkedList.h"
#include <functional>
#include <cmath>
#include <iostream>

using namespace std;

MyHashTable::MyHashTable(){
    this->size = 0;
    this->sizeA = 11;
    this->tabla = new MyLinkedList[this->sizeA];
}
//Complejidad: O(n)
MyHashTable::~MyHashTable(){
    for(int i=0; i<sizeA;i++){
        this->tabla[i].~MyLinkedList();
    }
    delete[]tabla;
}
//Complejidad: O(1)
bool MyHashTable::isEmpty(){
    return this->size ==0;
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
    this->tabla[key,pos].insertfirst(key,value);
}
//Complejidad: O(n)
int MyHashTable::get(string key){
    int pos = getPos(key);
    MyLinkedList* lista = &this->tabla[pos];
    return lista->getAt(key);
}
//Complejidad: O(1)
void MyHashTable::remove(string key){
    int pos = getPos(key);
    int x = stoi(key);
    this->tabla[pos].removeat(x);
    this->size--; 
}

void MyHashTable::rehashing(){//O(n)
    MyLinkedList* temp;
    int tempSize = this->size;
    temp = this->tabla;
    this->tabla = new MyLinkedList[(this->sizeA*2)+1]();
    this->size = 0;
    this->sizeA = (this->sizeA * 2) + 1;
    for(int i=0; i < tempSize ; i++){
        MyNodeLL* nodo = temp[i].first();

        while(nodo != nullptr){
            int pos=getPos(nodo->key);
            this->tabla[pos].insertfirst(nodo->key, nodo->data);
            this->size++; 

            nodo = nodo->next;
        }
    }
    delete[]temp;
}