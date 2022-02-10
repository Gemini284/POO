#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

    #include <vector>

    template <class T>
    class DoubleLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int numElements;
    public:
        public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        void swap(T &a, T &b);
        void quickSortIterative();
        Node<T> partition(Node<T> *l, Node<T> *h);
        void swap(Node<T> *a, Node<T> *b);
    };
#endif