//Sofia del Pilar Batiz Martinez A01634125. Este programa se hizo con ayuda de Gibran ya que ambos presentamos problemas en el DFS
//También me apoye en el libro de Estructura de datos para el intento de replicación de los métodos de viaje 
//Cuidado con el DFS, porque cuando lo corre me explota el programa pero a mi compañero Gibran no.
#include <iostream>
#include "MyGraph.h"
#include <vector>
#include <stack>
#include <queue>
using namespace std;
//Complejidad : O(1)
MyGraph::MyGraph(vector<vector<int>>& matriz){
    loadGraph(matriz);
}
//Complejidad : O(1)
void MyGraph::loadGraph(vector<vector<int>>& matriz){
    this->matriz = matriz;
}

//Complejidad Computacional: O(n log n)
void MyGraph::BFS(){
    int N = matriz.size();
    queue<int> fila;
    vector<bool> status(N,false);
    int data;

    for(int i = 0; i < N; i++){
        if(!status[i]){
            fila.push(i);

            status[i] = true;
            while(!fila.empty()){
                data = fila.front();
                fila.pop();
                cout << (data) << ",";
                for(int j = 0;j< matriz[data].size()-1;j++){
                    if(this->matriz[data][j] && !status[j]){
                        fila.push(j);
                        status[j] = true;
                    }
                }
            }
        }
    }
    cout << endl;
}


//Complejidad Computacional: O(n log n)
void MyGraph::DFS(){//O(n log n)
    int n=this->matriz.size();
    stack<int> pila;
    int data;
    vector<bool> status(n, false);
    for (int i = 0; i < n; i++) {
        if (!status[i]) {
            pila.push(i);
            while (!pila.empty()) {
                data = pila.top();
                pila.pop();
                if (!status[data]) {
                    cout << data <<",";
                    status[data] = true;
                    for (int j = 0; j< this->matriz[data].size()-1; j--) {
                        if (!status[this->matriz[data][j]]) {
                            pila.push(this->matriz[data][i]);
                        }  
                    }   
                }   
            }
        }
    }
    cout<<endl;
}
 
 
int main(){
    vector < vector <int> > ayu{{1,1,1,1},
                                 {1,0,0,0},
                                 {1,1,0,1},
                                 {1,1,1,0}};
    MyGraph grafo(ayu);
    cout<<"DFS"<<endl;
    grafo.DFS();
    cout<<"BFS"<<endl;
    grafo.BFS(); 



    return 0;
}