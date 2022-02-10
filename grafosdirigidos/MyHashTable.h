#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <string>
#include "MyLinkedList.h"

using namespace std;

class MyHashTable{
private:
    MyLinkedList* tabla;
    int size; //Cantidad de valores que hay almacenados en la Tabla
    int sizeA; //Tamaño del arreglo
    int getPos(string key);
public:
    MyHashTable();
    ~MyHashTable();
    bool isEmpty();
    void put(string key, int value);
    int get(string key);
    void remove(string key);
    void rehashing();
    
}; 
#endif