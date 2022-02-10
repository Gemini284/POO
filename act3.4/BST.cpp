#include <iostream> 
#include <iomanip>
#include <string>
#include "BST.h"

using namespace std;


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

// Método que convierte a double las direcciones IP y las guarda en un vector.
// Recibe un vector<vector<string>> y regresa un vector<double>
vector<double> BST::copiaIp(vector<vector<string>> &vec){ //O(n^2)
    vector<double> copia;
    for(int i = 0; i < vec.size();i++){
        string valor = vec[i][3];
        vector<double> separador;
        size_t pos;
        
        while((pos = valor.find('.')) != string::npos || (pos = valor.find(':')) != string::npos){
            separador.push_back(stoi(valor.substr(0, pos)));
            valor.erase(0, pos + 1);
        }

        separador.push_back(stoi(valor));
        copia.push_back((separador[0] * 10000000) + (separador[1] * 100000) + (separador[2] * 100) + (separador[3]));
    }
    return copia;
}


//Método que crea un nodo según el valor recibido
//Recibe la raíz y el valor a insertar
BST* BST::insert(BST* root, double value){ //O(1)

    if (!root){
        return new BST(value);
    }
 
    if (value >= root -> ip){
        if (value == root -> ip){
            root-> key += 1;
            return root;
        }
        root -> right = insert(root -> right, value);  
    }

    else{
        if (value == root -> ip){
            root-> key += 1;
            return root;
        }
          root -> left = insert(root -> left, value); 
    }
    return root;
}


//Método que realiza el recorrido del árbol en inorden inverso y obtiene las IPs repetidas
//Recibe la raíz
void BST::inorden(BST* root){ //O(1)
    if (!root) {
        return;
    }

    inorden(root -> right);
    
    if (root -> key > 1){ //Sólo muestra IP que se repiten
        cout << setprecision(0) << fixed << root -> ip << "(";
        cout << root -> key << " accesos)" << endl;
    }
    
    inorden(root -> left);
}