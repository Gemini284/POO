//Sofia del Pilar Batiz Martinez A01634125
//Este programa se creó con la ayuda de GeeksforGeeks y con ayuda de Gibran para el isTree()
#include <iostream>
#include "MyGraph.h"
#include <vector>
#include <stack>
#include <queue>
using namespace std;


//constructor de Mygraph 
MyGraph::MyGraph(vector<vector<int>>& matriz){
    loadGraph(matriz);
}

//Carga la matriz dada por el usuario
void MyGraph::loadGraph(vector<vector<int>>& matriz){
    this->matriz = matriz;
}


//funcion complementaria del istree
//Complejidad O(n)
bool MyGraph::Treegraph(int x, bool status[], int father){
    status[x] = true;
    vector<int>::iterator i;
    for(i = matriz[x].begin(); i != matriz[x].end(); ++i){
        if(!status[*i]){
            if(Treegraph(*i,status,x)){
                return true;
            }
        }else if(*i != father){
            return true;
        }
    }
    return false;
}

//Funcion que comprueba si un grafo es un arbol
//complejidad O(1)
bool MyGraph::isTree(){
    int v = matriz.size();
    bool *status = new bool[v];
    for(int i = 0; i < v; i++){
        status[i] = false;
    }

    if(Treegraph(0,status,-1)){
        return false;
    }
    for(int n = 0; n < v; n++){
        if(!status[n]){
            return false;
        }
    }
    return true;
}
//funcion que va ordenando la matriz
//complejidad O(n)
void MyGraph::Toposort(int x, bool status[], stack<int>& stack){
    status[x] = true;
    vector<int>::iterator i;
    for(i = matriz[x].begin(); i != matriz[x].end();i++){
        if(!status[*i]){
            Toposort(*i,status,stack);
        }
    }
    stack.push(x);
}

//Funcion que ordena la matriz
//Complejidad O(n)
void MyGraph::topologicalSort(){
    
    stack<int> stack;

    int v = matriz.size();

    bool* status = new bool[v];
    for(int i = 0; i < v; i++){
        status[i] = false;
    }

    for(int i =0; i< v; i++){
        if(status[i] == false){
            Toposort(i,status,stack);
        }
    }

    while(stack.empty() == false){
        cout << stack.top() << ",";
        stack.pop();
    }
}

//Funcion que comprueba si el grafo es bipartito
//Complejidad O(log n)
bool MyGraph::bipartiteGraph(){
    int v = matriz.size();
    int color[v];
    int src = 0;
    for(int i = 0; i < v; i++){
        color[i] = -1;
    }
    color[src] = 1;

    queue<int> lista;
    lista.push(src);
    while(!lista.empty()){
        int u = lista.front();
        lista.pop();
        if(matriz[u][u] == 1){
            return false;
        }
        for(int j = 0; j< v; j++){
            if(matriz[u][j] && color[j] == -1){
                color[j] = 1 -color[u];
                lista.push(j);
            }else if(matriz[u][j] && color[j] == color[u]){
                return false;
            }
        }
    }
    return true;
}

int main(){                   
    vector<vector<int>> matriz = {{0, 1, 0, 1, 1, 0, 0, 0},
                                   {1, 0, 1, 0, 0, 1, 0, 0}, 
                                   {0, 1, 0, 1, 0, 0, 1, 0},
                                   {1, 0, 1, 0, 0, 0, 0, 1},
                                   {1, 0, 0, 0, 0, 1, 0, 1},
                                   {0, 1, 0, 0, 1, 0, 1, 0},
                                   {0, 0, 1, 0, 0, 1, 0, 1},
                                   {0, 0, 0, 1, 1, 0, 1, 0}};
    MyGraph graph(matriz);
    
    //cout << graph.isTree() << endl;
    if(graph.isTree() == false){
        cout << "El grafo no  es un arbol" << endl;
    }else{
        cout << "El grafo es un arbol" << endl;
    }
    graph.topologicalSort();
    cout << endl;
//    cout << graph.bipartiteGraph() <<endl;
    if(graph.bipartiteGraph() == false){
        cout << "El grafo no es bipartito" << endl;
    }else{
        cout << "El grafo es bipartito" << endl;
    }
    return 0;
}

