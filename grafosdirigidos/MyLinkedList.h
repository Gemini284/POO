#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <iostream>
using namespace std;
struct MyNodeLL{
    string key;
    int data;
    MyNodeLL* next;

    MyNodeLL(string key,int data,MyNodeLL* next){
        this->key = key;
        this->data = data;
        this->next = next;
    }
    MyNodeLL(string key,int data):MyNodeLL(key,data,nullptr){}
};

class MyLinkedList{
private:
    MyNodeLL* first;
    MyNodeLL* last;
    int size;

public:
    MyLinkedList();
    int length();
    int first();
    void insertfirst(string key,int data);
    int getAt(string key);
    bool isEmpty();
    void removeFirst();
    void removelast();
    void removeat(int pos);
    friend ostream& operator<<(ostream& os,const MyLinkedList& ll){
        MyNodeLL* current = ll.first;
        for(int i = 0; i <= ll.size;i++){
            os<<current->data<<",";
            current=current->next;
        }
        return os;
    }
}; 
#endif