#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <iostream>
#include <ostream>


struct MynodoLL{
	int data;
	MynodoLL *next;

	MynodoLL(int data, MynodoLL *next){
		this -> data = data;
		this -> next = next;

	}

	MynodoLL(int data):MynodoLL(data,nullptr){};
};

class MyLinkedList{
	private:
		MynodoLL* head;
		MynodoLL* tail;
		int size;
		
	public:
		MyLinkedList();
		int first();
		int last();
		int length();
		void insertFirst(int data);
		void insertLast(int data);
		void insertAt(int data, int pos);
		int getAt(int pos);
		void setAt(int data, int pos);
		bool isEmpty();
		void removeFirst();
		void removeLast();
		void removeAt(int pos);

	 	friend std::ostream& operator<<(std::ostream& os,const MyLinkedList& ll){
         MynodoLL* current = ll.head;
         for(int i = 0; i < ll.size;i++){
             os << current -> data << ",";
             current = current -> next;
			}
	 	return os;
	 	}
		~MyLinkedList();
};

#endif