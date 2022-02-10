#ifndef MYGRAP_H
#define MYGRAPH_H
#include <vector>
#include <iostream>
using namespace std;

class MyGraph{
    private:
    vector<vector<int>> matriz;
    public:
    MyGraph (vector <vector<int>> &matriz);
    void loadGraph (vector<vector<int>>& matriz);
    void DFS(); //0,1,2,3,4,5
    void BFS();//0,1,2,3,4,5

};
#endif