//Ariadna Minerva Solis Naranjo
//A016309943
//Act 4.2 Grafos Complementarios

#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <vector>

using namespace std;


class MyGraph {
    private:
        vector< vector<int> > matrix;
        bool cicle(int n, bool visited[], int m);
        void topologicalSortRecursive(int v, bool visited[], stack<int>& stack);
        bool isBipartite(int src, int colorArr[]);

    public:
        MyGraph(vector< vector<int> >& matrix);
        void loadGraph(vector< vector<int> >& matrix);
        bool isTree();
        void topologicalSort();
        bool bipartiteGraph();
};

#endif

 

 