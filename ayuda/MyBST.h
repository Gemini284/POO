//Act 3.1 Operaciones Avanzadas en un BST
//Ariadna Minerva Solis Naranjo
//A01639943

#ifndef MYBST_H
#define MYBST_H
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
 

struct MyNodeBST{
    vector<string> data;
    int key;
    MyNodeBST *left,
              *right;
    MyNodeBST(vector<string> data){
        this->data = data;
        int key = 1;
        this->left=this->right=nullptr;
    }



};
 

class MyBST{
    private:
        int size;
        MyNodeBST* root;
        int mayor (vector<string> op1, vector<string> op2);
        int menor (vector<string> op1, vector<string> op2);
        int igual (vector<string> op1, vector<string> op2);
        vector<string> separaIp(vector<string> id);
        MyNodeBST* insert(MyNodeBST* current, vector<string> data);
        bool remove(MyNodeBST** current, int data);
        void heapify(int i);
        void level(MyNodeBST* current);
        void printLevel(MyNodeBST* current, int level);
        int height(MyNodeBST* current);
        //volver a poner el search
        
    public:
        MyBST();
        int length();
        bool isEmpty();
        void orderTree();
        bool search(vector<string>data);
        void insert(vector<string>data);
        bool remove(vector<string>data);
        void level();//De arriba-abajo, izquierda-derecha
        void imprimirArbol();
        int height();
};

MyBST::MyBST() {
    this->root = nullptr;
    this->size = 0;
}

int MyBST::length() {
    return this->size;
}

bool MyBST::isEmpty() {
    return this->size == 0;
}

MyNodeBST* MyBST::insert(MyNodeBST *current,vector<string> data){ //O(n)
    if ( igual(current->data, data) ){
        current->key++;
        return current;
    }else if(current==nullptr){
        return new MyNodeBST(data);
    }else if(mayor(data,current->data)){
        MyNodeBST *nvo=insert(current->left,data);
        current->left=nvo;
        return current;
    }else{
        MyNodeBST *nvo=insert(current->right,data);
            current->right=nvo;
            return current;
    }
}
void MyBST::insert(vector<string>data){ //O(n)
    if(this->root==nullptr){
        this->root=new MyNodeBST(data);
        this->size++;
    }else{
        MyNodeBST *nvo=insert(this->root,data);
        this->size++;
    }
}

int MyBST::mayor (vector<string> op1, vector<string> op2) { //Aqui se compararon los ips
    vector<string> id1,id2;
    id1 = separaIp(op1);
    id2 = separaIp(op2);

    if (stoi(id1[0]) > stoi(id2[0])){
        return 1;
    } else if ( stoi(id1[0]) == stoi(id2[0]) ){
        if (stoi(id1[1]) > stoi(id2[1])){
           return 1; 
        }else if (stoi(id1[1]) == stoi(id2[1])) { 
            if (stoi(id1[2]) > stoi(id2[2])) {
                return 1;
            } else if(stoi(id1[2])==stoi(id2[2])){
                if(id1[3]>id2[3]){
                    return 1;
                }else if(stoi(id1[3])==stoi(id2[3])){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                return 0;
            }
        } else {
            return 0;
        }   
    } else {
        return 0;
    }
}

int MyBST::igual(vector<string> op1, vector<string> op2){
        vector<string> id1,id2;
        id1 = separaIp(op1);
        id2 = separaIp(op2);
        if ( stoi(id1[0]) == stoi(id2[0]) ) {
            if ( stoi(id1[1]) == stoi (id2[1]) ) {
                if ( stoi(id1[2]) == stoi(id2[2]) ) {
                    if ( stoi(id1[3]) == stoi(id2[3]) ) {
                        return 1;
                    } else {
                        return 0;
                    }
                }else {
                    return 0;
                }
            }else{
                return 0;
            }
        }else {
            return 0;
        }
    }

vector<string> MyBST::separaIp(vector<string> id){
    vector<string> nvoip;
    stringstream sstr(id[3]);
    while(sstr.good()){
        string substr;
        getline(sstr,substr,'.'); //id[0]
        nvoip.push_back(substr);
        getline(sstr,substr,'.'); //id[1]
        nvoip.push_back(substr);
        getline(sstr,substr,'.'); //id[2]
        nvoip.push_back(substr);
        getline(sstr,substr,':'); //id[3]
        nvoip.push_back(substr);
    }
    return nvoip;
    }

void MyBST::level(MyNodeBST *current){
    cout<<"Entrada: Arcane se estrena hoy"<<endl;
    int h=height(current);
    cout<<"que tal tu mañana"<<endl;
    for(int i=0;i<h;i++){
        printLevel(this->root,i);
    }
}

void MyBST::printLevel(MyNodeBST *current,int level){ //tercera funcion de level
    cout<<"si entro al print"<<endl;
    if(current==nullptr){
        return;
    }if(level==0){
        cout<<"mayor que cero"<<endl;
        for (int i = 0; i < 4; i++) {
            cout<<current->data[3]<<" - ";
            cout<<current->key<<endl;
        }
    }else if(level>0){
        cout<<"menor que cero"<<endl;
        printLevel(current->left,level-1); //Va a buscar datos de derecha o de izquierda hasta que el nivel sea -1
        printLevel(current->right,level-1);
    }
}

void MyBST::level(){
    cout<<"Helou world of otakos"<<endl;
    level(this->root);
    cout<<endl;
}

int MyBST::height(MyNodeBST* current){ 
    cout<<"alturacion"<<endl;
    int heightLeft, heightRight;
    if (current == nullptr){
        return 0;
    } else {
        heightLeft = height(current->left);
        heightRight = height (current->right);
        if (heightLeft > heightRight){
            return heightLeft + 1;
        } else {
            return heightRight + 1;
        }
    }
    cout<<"regreso alturacion"<<endl;
}

int MyBST::height(){
    return height(this->root);
}

#endif