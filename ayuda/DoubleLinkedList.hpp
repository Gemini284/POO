#ifndef _DOUBLELINKEDLIST_HPP_
#define _DOUBLELINKEDLIST_HPP_

    #include <climits>
    #include "Node.hpp"
    #include "Stack.hpp"
    #include <vector>

    template <class T>
    class DoubleLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int numElements;

    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        int getNumElements();
        void printList();
        void addFirst(T &value);
        void addLast(T &value);
        bool deleteData(T value);
        bool deleteAt(int position);
        T getData(int position);
        T findData(T value);
        T operator [](const T &position);
        T operator=(const T &list);
        void clear();
        void sort();
        void swap(T &a, T &b);
        void duplicate();
        void removeDuplicates();
        //Nuevas funciones
        void quickSortIterative();
        Node<T> partition(Node<T> *l, Node<T> *h);
        void swap(Node<T> *a, Node<T> *b);
        
    };

    template<class T>
    DoubleLinkedList<T>::DoubleLinkedList() {
        std::cout << "--->Creando una lista vacia " << this << std::endl;
        head = NULL;
        tail = NULL;
        numElements = 0;
    }
  
    template<class T>
    DoubleLinkedList<T>::~DoubleLinkedList() {
        std::cout << "--->Liberando memoria de la lista " << this << std::endl;
        Node<T> *p, *q;
        p = head;
        while (p != NULL) {
            q = p->next;
            delete p;
            p = q;
        }
        head = NULL;
        tail = NULL;
        numElements = 0;
    }
 
    template<class T>
    int DoubleLinkedList<T>::getNumElements() {
        return numElements;
    }
    template<class T>
    void DoubleLinkedList<T>::printList() {
        Node<T> *ptr = head;
        while (ptr != NULL) {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }

    template<class T>
    void DoubleLinkedList<T>::addFirst(T &value) {
        Infor a(value);
        Node<T> *newNode = new Node<T>(a);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        numElements++;
    }
  
    template<class T>
    void DoubleLinkedList<T>::addLast(T &value) {
        if (head == NULL) {
            addFirst(value);
        }
        else {
            Infor a(value);
            Node<T> *newNode = new Node<T>(a);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            numElements++;
        }    
    }
  
    template<class T>
    bool DoubleLinkedList<T>::deleteData(T value) {
        Node<T> *p, *q;
        p = head;
        q = NULL; 
        if (p == NULL) {
            return false;
        }
        else {
            while (p != NULL && p->data != value) {
                q = p;
                p = p->next;
            }
            if (p == NULL)
                return false;
            if (p->prev == NULL) {
                head = p->next;
                if (head != NULL)
                    head->prev = NULL;
            }
            else if (p->next == NULL) { 
                q->next = NULL;
                tail = q;
            }
            else {
                q->next = p->next;
                p->next->prev = q;
            }
            delete p;
            numElements--;
            return true;
        }
    }

    template<class T>
    bool DoubleLinkedList<T>::deleteAt(int position) {
        if (position < 0 || position >= numElements) {
            std::cout << "Indice fuera de rango" << std::endl;
            return false;
        }
        else if (position == 0) {
            Node<T> *p = head;
            if (head != NULL && head->next == NULL) {
                head = NULL;
                tail = NULL;  
            }
            else {
                head = p->next;
                head->prev = NULL;
            }
            delete p;
            numElements--;
            return true; 
        }
        else { 
            Node<T> *p = head, *q = NULL;
            int index = 0;
            while (index != position) {
                q = p;
                p = p->next;
                index++;
            }
            if (p->next == NULL) {
                q->next = NULL;
                tail = q;
            }
            else { 
                q->next = p->next;
                p->next->prev = q;
            }
            delete p;
            numElements--;
            return true;
        }
    }
  
    template<class T>
    T DoubleLinkedList<T>::getData(int position) {
        /*if (position < 0 || position >= numElements) {
            std::cout << "Indice fuera de rango" << std::endl;
            return -1;
        }
         else {*/
        if (position >= 0 && position < numElements) {
            if (position == 0)
                return head->data;
            Node<T> *p = head;
            int index = 0;
            while (p != NULL) {
                if (index == position)
                    return p->data;
                index++;
                p = p->next;
            }
            //return -1;
        }
    }
    
    template<class T>
    T DoubleLinkedList<T>::findData(T value) {
        int index{0};
        Node<T> *p = head;
        while (p != NULL) {
            index++;
            if (value == p->data) {
                std::cout << "El valor se encuentra en la posicion " << index << std::endl;
                return index;
            }
            p = p->next;
        }
        /*std::cout << "El valor esta fuera de rango" << std::endl;
        return -1;*/
    }
    
    template<class T>
    T DoubleLinkedList<T>::operator[](const T &position) {
        if (position < 0 || position >= numElements) {
            std::cout << "Indice fuera de rango" << std::endl;
            return -1;
        }
        else {
            if (position == 0)
                return head->data;
            Node<T> *p = head;
            int index{0};
            while (p != NULL) {
                if (index == position) {
                    std::cout << "La posicion " << position << " apunta al valor " << p->data << std::endl;
                    return p->data;
                }
                index++;
                p = p->next;
            }
            return -1;
        }
    
    }
    
    template<class T>
    T DoubleLinkedList<T>::operator=(const T &list) {
        for (int i{0} ; i < list.numElements ; i++) {
            Node<T> *newNode = new Node<T>(list[i]);
            newNode->next = head;
            head = newNode;
            numElements++;
        }
        
        std::cout << "Lista copiada exitosamente" << std::endl;
    }
    
    template<class T>
    void DoubleLinkedList<T>::clear() {
        Node<T> *p, *q;
        p = head;
        while (p != NULL) {
            q = p->next;
            delete p;
            p = q;
        }
        head = NULL;
        tail = NULL;
        numElements = 0;
    }
    
    template<class T>
    void DoubleLinkedList<T>::sort() {
        int swapped;
        Node<T> *p, *q = NULL;
        p = head;

        if (head == NULL)
            return;
        do {
            swapped = 0;
            p = head;
    
            while (p->next != q) {
                if (p->data > p->next->data) {
                    swap(p->data, p->next->data);
                    swapped = 1;
                }
                p = p->next;
            }
            q = p;
        }
        while (swapped);
    }
    
    template<class T>
    void DoubleLinkedList<T>::swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }
    
    template<class T>
    void DoubleLinkedList<T>::duplicate() {
        Node<T> *p = tail;
        int newElements{0};
        for (int i{0} ; i < numElements ; i++) {
            Node<T> *newNode = new Node<T>(p->data);
            if (head == NULL) {
            head = newNode;
            tail = newNode;
            }
            else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            }
            p = p->prev;
            newElements++;
        }
        numElements +=  newElements;
    }
    
    template<class T>
    void DoubleLinkedList<T>::removeDuplicates() {
        if ((head) == NULL)
            return;
 
        int index{0};         
        std::vector<T> n;
        n.push_back(tail->data);
        Node<T> *p = head, *q;
        
        while (true) {
        
            if (p != NULL) {
                if (getData(index) == n.back()) {
                    q = p->next;
                    deleteAt(index);
                    p = q;
                }
 
                else {
                    n.push_back(p->data);
                    p = p->next;
                }
            } else {
                break;
            }
        }
    }
    
    /*Esta función utiliza los valores en las variables data del nodo para
    organizarse con el métoddo de Quick Sort. También utiliza un stack en
    su implementación.*/
    template <class T>
    void DoubleLinkedList<T>::quickSortIterative() {
        Node<T> *l = head;
        Node<T> *h = tail;
        Stack<Node<T> *> stk;
        
        stk.push(l);
        stk.push(h);
        
        while (!stk.isEmpty()) {
            h = stk.pop();
            l = stk.pop();
            
            Node<T> *p = new Node<T> (partition(l, h));
            
            if (p->data.getDate() > l->data.getDate()) {
                stk.push(l);
                stk.push(p->prev);
            }
            if (p->data.getDate() < h->data.getDate()) {
                stk.push(p->next);
                stk.push(h);
            }
        }
    }
    
    //Función de partition
    template <class T>
    Node<T> DoubleLinkedList<T>::partition(Node<T> *l, Node<T> *h) {
        Infor x = h->data;
        Node<T> *i = l->prev;
        
        for (Node<T> *j = l; j != h; j = j->next) {
            if (j->data.getDate() < x.getDate() || j->data.getDate() == x.getDate()) {
            i = (i == NULL) ? l : i->next;
            swap(i, j);
            }
        }
        i = (i == NULL) ? l : i->next;
        swap(i, h);
        //Regresa el nodo modificado
        return *i;
    }
    
    //Función de swap, integral para el método de sorteo
    template <class T>
    void DoubleLinkedList<T>::swap(Node<T> *a, Node<T> *b) {
        T t = a->data;
        a->data = b->data;
        b->data = t;
    }
    
#endif // _DOUBLELINKEDLIST_HPP_
