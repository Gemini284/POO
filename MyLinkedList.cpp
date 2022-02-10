/*Este Trabajo lo hice en conjunto con mi compañero Alexis Gibrán Acosta Pánuco en las funciones setat, insertat y removeat por que se nos complico un poco el resto,
fue sacado del libro de texto y algunos videos que explicaban como insertar ya que el metodo insertlast del libro no funcionaba y las neuronas no nos daban. 
Además de una pregunta al compañero Manuel porque no había terminado de copiar el insertLast y al momento de preguntarle no estaba la grabación
y una pequeña asesoria con Ariadna */
#include "MyLinkedList.h"
#include <limits>
#include <iostream>

using namespace std;

MyLinkedList::MyLinkedList(){
		this -> size = 0;
		this -> head = this -> tail = nullptr;
};//Listooo

int MyLinkedList::first(){
	return this -> head -> data;
}//listoo

int MyLinkedList::last(){
	return this -> tail -> data;
}//listoo

int MyLinkedList::length(){
	return this -> size;
	
}

bool MyLinkedList::isEmpty(){ //O(n)
	if(this -> size == 0){
 		return true;
	}else{
		return false;
 	}
}

void MyLinkedList::insertFirst(int data){ //O(1)
	this -> head = new MynodoLL(data,this-> head);

	if(this-> size == 0){
		this -> tail = this -> head;
	}else{
		this -> size++;
    }
}//Listo

void MyLinkedList::removeFirst(){ //O(1)
	if(this -> size > 0){
		MynodoLL*tmp = this -> head;
		this -> head = this -> head -> next;
		delete tmp;
		this -> size--;
	}
	
	if(this -> size == 0){
		this -> tail = nullptr;
	}else{
		throw invalid_argument("No se puede acceder");
	}
} //Listo

void MyLinkedList::insertLast(int data){ //O(1)
	this->tail->next = new MynodoLL(data);
	if (this->size == 0){
		this ->tail =this->head;
	}
	this->size++;
}

void MyLinkedList::removeLast(){ //(O )
	if(this->size > 0){
		MynodoLL *tmp =this-> head;
		MynodoLL *current;
		while(tmp->next->next != nullptr){ //segundo ultimo nodo 
			tmp = tmp->next;
			current = tmp->next;
		}
		tmp->next = nullptr;
		delete(current);
		this->size--;
	}
	else{
		throw invalid_argument("No se puede acceder al último elemento");
	}
}

void MyLinkedList::setAt(int data,int pos){//O(N)
    if(pos >= 0 && pos <this->size){
        MynodoLL* tmp = this->head;
        for(int i = 0; i < pos-1;i++){
            tmp = tmp->next;
        }
        MynodoLL* nuevo = new MynodoLL(data,tmp->next);
        nuevo->next = tmp->next;
        tmp->next = nuevo;
        
    }else{
        throw invalid_argument("No se puede acceder a la posicion" +to_string(pos)+" en una lista de tamaño"+to_string(this->size));
    }
}

int MyLinkedList::getAt(int pos){ //O(n)
	if(pos>=0 && pos<this->size){
		MynodoLL* current= this->head;
		for(int i=0;i<pos;i++){
			current = current->next;
		}
		return current -> data;
	}else{
		throw invalid_argument("No se puede acceder a la posición"+to_string(pos)+ "en una lista de tamaño"+to_string(this->size));
	}
}//listo

void MyLinkedList::insertAt(int data,int pos){ //O(n)
    if(pos > 0 && pos <this->size){
        MynodoLL* temp;
        MynodoLL* temp2;
        MynodoLL* nuevo;
        nuevo->data = data;
        temp2 = this->head;
        int tempos = 0;
        while(temp2->next != NULL && tempos != pos){
            temp = temp2;
            temp2 = temp2->next;
            tempos++;
        }
        temp->next = nuevo;
        nuevo->next = temp2;
    }else{
       throw invalid_argument("No se puede acceder a la posicion" +to_string(pos)+" en una lista de tamaño"+to_string(this->size));
    }
    this->size++;
}


 void MyLinkedList::removeAt(int pos){//O(N)
    if(pos > 0 && pos <this->size){
    MynodoLL* tmp = this->head;
    MynodoLL* elimina;
    for(int i = 0; i < pos-1;i++){
            tmp = tmp->next;
        }
    elimina = tmp->next;
    tmp->next = elimina->next;
    delete elimina;
    }else{
        throw invalid_argument("No se puede acceder a la posicion" +to_string(pos)+" en una lista de tamaño"+to_string(this->size));
    }

}
MyLinkedList::~MyLinkedList(){

};

int main() {

    return 0;
}