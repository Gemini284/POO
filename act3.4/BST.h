#include <iostream> 
#include <queue>
#include <string>


using namespace std;

class BST{
    double ip;
    int key;
    struct BST *left, *right;

    public:
        BST(); //O(1)
        BST(double); //O(1)
        static vector<double> copiaIp(vector<vector<string>> &); //O(n^2)
        BST* insert(BST*, double); //O(1)
        void inorden(BST*); //O(n)
};