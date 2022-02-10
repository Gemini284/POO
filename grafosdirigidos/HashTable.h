#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class HashTable{
    private:
        static const int hashGroups=10; //DEBO CAMBIARLO PORQUE NO ES DINAMICO
        list<pair<int, string>> table [hashGroups]; //COMO SI EXISTIERA UNA LINKED LIST
        //int size; //Cantidad de valores que hay almacenados en la tabla
        int sizeA;//Tamaño del Arreglo
        // int getPos(string key);
    public:
        HashTable();
        ~MyHashTable();
        bool isEmpty();
        void put(int key, string value); //+
        int get(int key); //hashFunction
        void remove(int key);
        void printTable();
};

#endif