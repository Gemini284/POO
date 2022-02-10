//Ariadna Minerva Solis Naranjo
//A016309943
//Act 4.2 Grafos Complementarios

#include <queue>
#include <stack>
#include <iostream>
#include "MyGraph.h"

using namespace std;

MyGraph::MyGraph(vector< vector<int> >& matrix){//O(1)
    loadGraph(matrix);
}

void MyGraph::loadGraph(vector< vector<int> >& matrix){//O(1)
    this->matrix=matrix;
}

bool MyGraph::cicle(int n, bool visited[], int m) {//O(n log n)
    visited[n] = true;
    for (int i =0 ; i != this->matrix.size(); ++i) {
        if (!visited[i]) {
           if (cicle(i, visited, n)){
               return true;
            }  
        }
        else if (i != m) {
            return true;
        }
    }
    return false;
}


bool MyGraph::isTree() {//O(n)
    bool *visited = new bool[this->matrix.size()];
    for (int i = 0; i < this->matrix.size(); i++){
        visited[i] = false;
    }
    if (cicle(0, visited, -1)){
        return false;
    }
    for (int j = 0; j <= this->matrix.size(); j++){
        if (!visited[j]){
            return false;
        }  
    }
    return true;
}

void MyGraph::topologicalSortRecursive(int v, bool visited[], stack<int>& stack) {//O(n)
    visited[v] = true;
    for (int i = 0; i != this->matrix.size(); ++i){
        if (!visited[i]){
            topologicalSortRecursive(i, visited, stack);
        }
    }
    stack.push(v);
}

void MyGraph::topologicalSort() {//O(n)
    stack<int> stack;
    bool* visited = new bool[this->matrix.size()];
    for (int i = 0; i < this->matrix.size(); i++) {
        visited[i] = false;
    }
    for (int i = 0; i < this->matrix.size(); i++) {
        if (visited[i] == false){
            topologicalSortRecursive(i, visited, stack);
        }   
    }
    while (stack.empty() == false) {
        cout << stack.top() <<",";
        stack.pop();
    }
    cout<<endl;
}

bool MyGraph::isBipartite(int n, int array[]) {//O(n log n)
    array[n] = 1;
    queue<int> queue;
    queue.push(n);
    while (!queue.empty()) {
        int i = queue.front();
        queue.pop();
        if (this->matrix[i][i] == 1){
            return false;
        }
        for (int j = 0; j < this->matrix.size(); ++j) {
            if (this->matrix[i][j] && array[j] == -1) {
                array[j] = 1 - array[i];
                queue.push(j);
            }
            else if (this->matrix[i][j] && array[j] == array[i]){
                return false;
            }   
        }
    }
    return true;
}
 

bool MyGraph::bipartiteGraph() {//O(n log n)
    int array[this->matrix.size()];
    for (int i = 0; i < this->matrix.size(); ++i){
        array[i] = -1;
    }
    for (int i = 0; i < this->matrix.size(); i++){
        if (array[i] == -1){
            if (isBipartite(i, array) == false){
                return false;
            }
        }    
    }
    return true;
}

int main(){
    //Casos de prueba
    cout<<"\n\tCaso de prueba 1\n"<<endl;
    vector < vector <int> > segu{{0,0,1,0,1},
                                 {1,0,0,0,0},
                                 {1,0,0,1,1},
                                 {1,0,1,0,1},
                                 {1,1,1,1,1}};
    MyGraph grafo(segu);
    cout<<"\nTopological Sort"<<endl;
    grafo.topologicalSort();
    cout<<"\nEl grafo es bipartito? "<< grafo.bipartiteGraph() <<endl;
    cout<<"\nEl grafo es un arbol? "<< grafo.isTree() <<endl;

    cout<<"\n\tCaso de prueba 2\n"<<endl;
    vector < vector <int> > primis{{0,0,1,1},
                                   {1,0,1,0},
                                   {0,1,0,1},
                                   {1,1,1,0}};
    MyGraph grafi(primis);
    cout<<"\nTopological Sort"<<endl;
    grafi.topologicalSort();
    cout<<"\nEl grafo es bipartito? "<< grafi.bipartiteGraph() <<endl;
    cout<<"\nEl grafo es un arbol? "<< grafi.isTree() <<endl;

    cout<<"\n\tCaso de prueba 3\n"<<endl;
    vector < vector <int> > tercis{{0,1,1,0,0,0},
                                   {1,0,0,1,1,0},
                                   {1,0,0,0,0,1},
                                   {0,1,0,0,0,0},
                                   {0,1,0,0,0,0},
                                   {0,0,1,0,0,0}};
    MyGraph grafe(tercis);
    cout<<"\nTopological Sort"<<endl;
    grafe.topologicalSort();
    cout<<"\nEl grafo es bipartito? "<< grafe.bipartiteGraph() <<endl;
    cout<<"\nEl grafo es un arbol? "<< grafe.isTree() <<endl;


    return 0;
}