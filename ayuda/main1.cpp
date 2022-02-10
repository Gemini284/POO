//
//  main.cpp
//  Proyecto2
//
//  Created by Manuel Cardenas on 10/10/21.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "Acceso.h"
#include "Acceso.cpp"
#include "MyLinkedList.h"
#include "MyLinkedList.cpp"

void leeArchivo(MyLinkedList &lista){
    ifstream archivo;
    archivo.open("bitacora.txt");
    if (archivo.is_open()){
        string line;
        while(getline(archivo, line)){
            stringstream sstr(line);
            string dato;
            vector<string> vecAux;
            while (getline(sstr, dato, ' ')){
                vecAux.push_back(dato);
            }
            string errAcceso = vecAux[4];
            int tamanio = vecAux.size();
            for (int i = 5; i<tamanio; i++) {
                errAcceso += (" " + vecAux[5]);
                vecAux[4] = errAcceso;
                vecAux.erase(vecAux.begin()+5);
            }
            string ip = vecAux[3];
            stringstream lineaIp(ip);
            vector<string> dirIp;
            string comp = "";
            while (getline(lineaIp, comp,'.')){
                dirIp.push_back(comp);
            }

            string puerto = dirIp[3];
            stringstream lineaPuerto(puerto);
            vector<string> idPuerto;
            string comp2 = "";
            while (getline(lineaPuerto, comp2, ':')){
                idPuerto.push_back(comp2);
            }
            
            string mes = vecAux[0];
            int dia = stoi(vecAux[1]);
            string hora = vecAux[2];
            int ipA = stoi(dirIp[0]);
            int ipB = stoi(dirIp[1]);
            int ipC = stoi(dirIp[2]);
            int ipD = stoi(idPuerto[0]);
            int puertos = stoi(idPuerto[1]);
            string error = vecAux[4];
            Acceso datos = Acceso(mes, dia, hora, ipA, ipB, ipC, ipD, puertos, error);
            lista.insertLast(datos);
        }
        archivo.close();
    }else{
         cout<< "Error de lectura de archivo"<<endl;
    }

}

int main(){
    
    MyLinkedList lista, listaAux, lista2;
    
    int outnum = 1;
    string outname;
    bool out = true;
    char opcion;

    leeArchivo(lista);
    lista.ordena();
    lista.imprimeLista();
    
    listaAux = lista;
    
    //Pedirle los limites
    
    //Limite inferior
    int infA, infB, infC, infD;
    cout << "Limites inferiores" << endl;
    cin >> infA;
    cin >> infB;
    cin >> infC;
    cin >> infD;
    
    //Limite superior
    cout << "Limites superiores" << endl;
    int supA, supB, supC, supD;
    cin >> supA;
    cin >> supB;
    cin >> supC;
    cin >> supD;
    
    listaAux.limiteInf(infA, infB, infC, infD);
    
    listaAux.limiteSup(lista2, supA, supB, supC, supD);
    
    //lista.busquedaSup(lista2, supA, supB, supC, supD);
    //lista.busquedaInf(lista2, infA, infB, infC, infD);
    
    


/*
    while (out == true){
        outname = "salida" + to_string(outnum) + "-Eq5.txt";

        switch (opcion){
            case (constant-expression ):
            {
                break;
            }
            default:
                break;
        }
        if (outnum == 3){
            out = false;
        }else{
            outnum++;
        }

        
    }
    */
    return 0;
    
}
