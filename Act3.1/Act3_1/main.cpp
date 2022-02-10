//Elaborado por : 
//Jorge Daniel Cruz Case A01634536
//Fernanda Monserrat Galvan Romero A00344712
//Programa para el manejo de un BST

/*
* Ejemplo que implementa un Binary Search Tree 
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
      g++ -std=c++17 *.cpp -Wall
* Ejecucion:
*    ./main
**/
#include <iostream>
#include "BinarySearchTree.h"

int main() {
    system("cls");
    std::cout << "Prueba de un Binary Search Tree !\n";
    BinarySearchTree<int> myBST;
    int num;
    myBST.insert(10);
    myBST.insert(20);
    myBST.insert(30);
    myBST.insert(15);
    myBST.insert(5);
    myBST.insert(115);
    myBST.insert(3);
    myBST.insert(6);
    myBST.insert(12);
    myBST.insert(2);
    myBST.insert(1);

  /*
                    10
            5               20          
        3     6        15          30
      2              12                  115                           
    1
  */
    std::cout << "\nIngrese el numero a utilizar: ";
    std::cin>>num;
    std::cout << std::endl;
    //1.- Preorder
    //2.- Inorder
    //3.- Postorder
    //4.- Level by level
    for(int j = 1; j<5; j++){
        myBST.visit(j);
    }
    std::cout<<"\nAltura del arbol"<<std::endl;
    std::cout<<myBST.getHigh()<<std::endl;
    std::cout << "\nNivel en el que se encuentra el numero "<< num << std::endl;

    if(myBST.callwhatLevel(num) == -1){
        std::cout << "\nEl numero no esta en el arbol " << std::endl;
    }
    else{
        std::cout<<myBST.callwhatLevel(num)<<std::endl;
    }
    std::cout << "\nAncestros del numero "<<num << std::endl;
    myBST.callAncestors(num);
}