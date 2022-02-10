//Sofia del Pilar Batiz Martinez A01634125
#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <vector>
#include <stack>
using namespace std;

class MyGraph{
    private:
        vector<vector<int>> matriz;
        bool Treegraph(int x, bool status[], int father);
        void Toposort(int x,bool status[], stack<int>& stack);
    public:
        MyGraph(vector<vector<int>>& matriz);
        void loadGraph(vector<vector<int>>& matriz); 
        bool isTree();
        void topologicalSort();
        bool bipartiteGraph();
};

#endif