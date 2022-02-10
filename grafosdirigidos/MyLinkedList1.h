//
//  MyLinkedList.h
//  ListaEnlazada
//
//  Created by Manuel Cardenas on 24/09/21.
//

#ifndef MyLinkedList_h
#define MyLinkedList_h

#include <iostream>
using namespace std;

struct MyNodeLL {
    int data;
    string key;
    MyNodeLL* next;
    
    MyNodeLL(string key, int data, MyNodeLL* next){
        this->key = key;
        this->data = data;
        this->next = next;
    }
    
    MyNodeLL(string key, int data):MyNodeLL(key, data, nullptr){
        
    }
};

class MyLinkedList{
    private:
        MyNodeLL* head;
        MyNodeLL* tail;
        int size;
        
    public:
        MyLinkedList();
        int length();
        void insertFirst(string key, int data);
        int getAt(string key);
        //int getAt(int pos); //Tarea1
        bool isEmpty();
        void removeFirst();
        void removeLast();
        void removeAt(int pos);
        void ordenar(MyLinkedList L);
        void quitar(string key);
        friend ostream& operator<<(ostream& os, const MyLinkedList ll){
            MyNodeLL* current = ll.head;
            for(int i=0; i<ll.size; i++){
                os << current->data << ",";
                current=current->next;
            }
            return os;
        }
};

#endif /* MyLinkedList_h */
