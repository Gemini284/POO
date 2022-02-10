//
//  MyLinkedList.h
//  Proyecto2
//
//  Created by Manuel Cardenas on 10/10/21.
//

#ifndef MyLinkedList_h
#define MyLinkedList_h
# include "Acceso.h"

struct MyNodeLL{
    Acceso dato;
    MyNodeLL* next;
    MyNodeLL* prev;

    MyNodeLL(Acceso dato, MyNodeLL* next, MyNodeLL* prev){
        this->dato = dato;
        this->next = next;
        this->prev = prev;
    }

    MyNodeLL(Acceso dato):MyNodeLL(dato, nullptr, nullptr){}
};

class MyLinkedList{
    private:
        MyNodeLL* head;
        MyNodeLL* tail;
        int size;
    public:
        MyLinkedList();
        int length();
        void insertFirst(Acceso dato);
        void insertLast(Acceso dato);
        Acceso getAt(int pos);
        bool isEmpty();
        void imprimeLista();
        bool comparaMayorIpPuerto(MyNodeLL *A, MyNodeLL *B);
        void ordena();
        void removeFirst();
        void intercambio(MyNodeLL*, MyNodeLL*);
        void busquedaSup(MyLinkedList &L, int supA, int supB, int supC, int supD);
        void busquedaInf(MyLinkedList &L, int infA, int infB, int infC, int infD);
        void limiteSup(MyLinkedList &L, int supA, int supB, int supC, int supD);
        void limiteInf(int infA, int infB, int infC, int infD);
        void busqueda(MyLinkedList &L, int infA, int infB, int infC, int infD, int supA, int supB, int supC, int supD);
             
};

#endif /* MyLinkedList_h */
