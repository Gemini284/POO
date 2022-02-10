//Sofía del Pilar Batiz Martinez A01634125
#include "MyHeap.h"
#include <iostream>

using namespace std;

MyHeap heap;

MyHeap::MyHeap(){
    this->size =0;
    this->len=7; //Tamaño del arreglo
    this->values=new int[len]; //Arreglo :D
}
//Complejidad peor de los casos O(n^2) - los datos estan desordenados y el proceso se repite varias veces
// //Complejidad mejor de los casos O(n)- solo toma una iteracion realizarlo.
void createHeape(int values[],int len, int i){
    int mayor = i; //mayor como raíz
    int izq = (2*i)+1; //izquierdo obedece a 2*i + 1
    int der = (2*i)+ 2;//Derecha obedece a 2*i+2
    int ancestor = (i-1)/2;
    if(izq<len && values[izq]>values[mayor]){ //Si el izquierdo es mayor
        mayor=izq;
    }
    if(der<len && values[der]>values[mayor]){ //Si el derecho es mayor
        mayor=der;
     }
    if(mayor != i){
        swap(values[i], values[mayor]);
        createHeape(values,len, i); //vuelve el resto de el array un arbol
    }
}
//Peor caso: O(nlog(n)) = Todos los datos se acomodan y siempre el dato es menor que los anteriores
//Mejor caso: O (log(n)) = Todos los datos se acomodan pero hay un mayor que toma el lugar 0 y solo van para abajo
void construyeHeap(int values[], int len){
        for (int i = len/2; i >= 1; i--) {
        createHeape(values, len, i);
    }
}//Peor caso O(n)
void MyHeap::push(int n){
    if(this->size == this->len){
         len = 2*len + 1;
        for(int i = 0; i<len;i++){
            values[i] = this->values[i];
        }
     }
    values[size] = n;
    int nuevo = this->size;
    createHeape(values, len, n); 
    size++;
};
//Complejidad O(n)= Al solo eliminar el primer elemento solo tenemos un caso.
void MyHeap::pop(){
    int ultimEle = values[0];
    values[0]=values[(this->size-1)];//Cambia mi primer elemento (raíz) y el último elemento
    this->size--;
    createHeape(values, len, 0);
}
///Complejidad O(n)= Al solo mostrar el primer elemento solo tenemos un caso.
int MyHeap::top(){
    return values[0];
}
///Complejidad O(n)= Al solo mostrar el tamaño del heap y este es solo un caso.
int MyHeap::length(){
    return size;
}
//Complejidad O(n)= Solo se cuenta con un caso
bool MyHeap::isEmpty(){
    if (size==0){
        return true;
    }else{
        return false;
    }
}
/*      void MyHeap:: imprime(){
     for(int i =0;i < this->size ;i++){
        cout << values[i] << " " ;
     }
 } Función de chequeo */
int main(){
  
    return 0;
}