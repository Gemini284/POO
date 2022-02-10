#include <iostream>
#include "MyGraph.h"
#include <vector>
#include <stack>
#include <queue>
using namespace std;

MyGraph::MyGraph(vector<vector<int>>& matriz){
    loadGraph(matriz);
}

void MyGraph::loadGraph(vector<vector<int>>& matriz){
    this->matriz = matriz;
}

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
                for(int i = matriz[data].size()-1; i >=0;i--){
                    if(!status[matriz[data][i]]){
                        fila.push(matriz[data][i]);
                    }
                }
            }
        }
    }
    cout << endl;
}


void MyGraph::DFS(){
    int v = matriz.size();
    stack<int> lista;
    int data;

    vector<bool> status(v,false);
    for(int i = 0; i< v;i++){
        if(!status[i]){
            lista.push(i);

            while(!lista.empty()){
                data = lista.top();
                lista.pop();
                if(!status[data]){
                    cout << (data) << ",";
                    status[data] = true;
                    for(int j = 0; j<v; j++){
                        if(matriz[data][j] && !status[j]){
                            lista.push(j);
                            status[j] = true;
                        }
                    
                    }
                }
            }
            }
    }
    cout << endl;

}


 
 
int main(){
    vector<vector<int>> matriz {{1,2,3},
                                {6,7,8},
                                {9,4,5}}; 
    MyGraph h = MyGraph(matriz);
    h.loadGraph(matriz);
    h.DFS();
    h.BFS();

    return 0;
}