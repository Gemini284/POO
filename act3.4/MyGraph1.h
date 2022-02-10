#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <vector>
using namespace std;

class MyGraph{
    private:
        vector<vector<int>> matriz;
        void DFSre(vector<vector<int>> matriz);
    public:
        MyGraph(vector<vector<int>>& matriz);
        void loadGraph(vector<vector<int>>& matriz); 
        void DFS(); //sin espacio separados por comas 01,2,3,4,5,
        void BFS(); //sin espacio separados por comas 01,2,3,4,5,
};

#endif