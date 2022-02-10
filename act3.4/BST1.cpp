#include <iostream> 
#include <iomanip>
#include <string>
#include "BST1.h"
//Constructor default
BST::BST(){ //O(1)
    ip = 0;
    key = 1;
    left = NULL;
    right = NULL;
}
 

//Constructor con parámetros
BST::BST(double _ip) { //O(1)
    ip = _ip;
    key = 1;
    left = NULL;
    right = NULL;
}