// //Alexis Gibran ACosta Panuco A01639818
// //Programa que construye un arbol Heap, funciones de inserccion y eliminado
// #include "Myheap.h"
// #include <iostream>

// using namespace std;
// //constructor
// MyHeap::MyHeap(){
//     this->values = new int[len];
//     this->len = 7;
//     this->size = 0;

// }

// //Funcion que intercambia los elementos del arreglo 
// void MyHeap::swap(int* x, int* y){
//     int tmp = *x;
//     *x = *y;
//     *y =tmp;
// }

// //Funcion que ordena el arbol hacia arriba
// //Complejdad peor de los casos O(n log n)- Varios datos estan antes de lo que deberian
// //complejidad mejor de los casos O(log n)- todos los datos estan acomodados en orden
// void MyHeap::up(int nuevo){
//     while(values[nuevo] > values[(nuevo-1)/2]){
//         swap(&values[nuevo],&values[(nuevo-1)/2]);
//         nuevo = (nuevo-1)/2;
//     }
// }

// //Metodo recursivo para ordenar el arbol 
// //Complejidad peor de los casos O(n^2) - los datos estan desordenados y el proceso se repite varias veces
// //Complejidad mejor de los casos O(n)- solo toma una iteracion realizarlo.
// void MyHeap::down(int x){
//     int hijoizq = (2*x);
//     int hijoder = (2*x) + 1;
//     int ancestor = (x-1)/2;
//     if(values[x] < values[hijoizq] || values[x] < values[hijoder]){
//         if(values[hijoizq] > values[hijoder]){
//             swap(&values[x],&values[hijoizq]);
//             down(hijoizq);
//         }else{
//             swap(&values[x],&values[hijoder]);
//             down(hijoder);
//         }
//     }
// }

// //Metodo que inserta un nuevo elemento dentro del arbol
// //Mejor y peor caso complejidad O(n)
// void MyHeap::push(int n){
//     if(this->size == this->len){
//         len = 2*len + 1;
//     }
//     values[size] = n;
//     int nuevo = this->size;
//     up(nuevo);
//     this->size++;
// }
// //Metodo que elimina un elemento dentro del arbol
// //Mejor y peor caso complejidad O(n)
// //Se ejecuta solo una vez por lo cual solo se necesita un caso
// void MyHeap::pop(){
//     int elimina = values[0];
//     values[0] = values[(this->size-1)];
//     this->size--;
//     down(0);
// }
// //complejidad mejor y peor caso O(1)
// //Funcion que regresa el valor de la raiz
// int MyHeap::top(){
//     return values[0];
// }

// //funcion que comprueba si el arbol esta vacio o no
// //Complejidad mejor y peor caso O(n)
// bool MyHeap::isEmpty(){
//     if(this->size == 0){
//         return true;
//     }else{
//         return false;
//     }
// }

// //Funcion que regresa el tamaño del arbol (el numero de elementos que contiene)
// //Complejidad mejor y peor caso O(n)
// int MyHeap::length(){
//     return this->size;
// }

// //Funcion propia utlizada para casos de prueba
// //Complejidad mejor y peor caso O(n)
// void MyHeap::imprime(){
//     for(int i =0;i < this->size;i++){
//         cout << values[i] << " " ;
//     }
// }


// //inserte su main aqui:)



// //Main de prueba utlizado para comprobar que todas la funciones funcionen correctamente

// int main(){
//     MyHeap heap;
//     heap.push(28);
//     heap.push(21);
//     heap.push(17);
//     heap.push(19);
//     heap.push(5);
//     heap.push(8);
//     heap.push(20);
//     cout<< heap.top()<<endl;
//     heap.imprime();
//     cout << endl;
//     heap.pop();
//     heap.imprime();
//     cout << endl;
//     cout<< heap.top();
//     cout << endl;
//     cout<< heap.length();
// }