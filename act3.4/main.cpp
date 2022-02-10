/* 
Act 3.4 - Actividad Integral de BST

Programa que:
- Abre el archivo de entrada
- Agrega todos los accesos por ip y los almacena en una estructura tipo BST dónde la llave será el número de accesos y el valor es la dirección IP
- Encuentre las cinco IPs con más accesos.

Autores: 
- Ernesto Reynoso Lizárraga A01639915
- María Fernanda Elizalde Macías A01634135
- Paola Elizabeth Gómez Martínez A01633772

Fecha: 30 de octubre de 2021

*/

#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>


using namespace std;


int main() {
    
	// DefiniciÓn variables
	string mes, dia, hora, id, razon; 

    // Declaración de vectores
	vector<string> mesVec;
	vector<string> diaVec;
	vector<string> horaVec;
	vector<string> idVec;
    vector<string> razonVec;

	// Lectura de archivo
	string file;
	file = "bitacora.txt";

	
	int i = 0; // Número de líneas

	ifstream bitac(file); // Abrir archivo
	if (bitac.is_open()) 
	{
        
		while (!bitac.eof()) // Mientras que no se llegue al final del archivo
        {
			// Llenar vectores
			getline(bitac, mes, ' ');
			mesVec.push_back(mes);
			getline(bitac, dia, ' ');
			diaVec.push_back(dia);
			getline(bitac, hora, ' ');
			horaVec.push_back(hora);
            getline(bitac, id, ' ');
			idVec.push_back(id);
			getline(bitac, razon, '\n'); // Nueva línea después de la razón
			razonVec.push_back(razon);
			
			i += 1; 
		}
		bitac.close(); // Cerrar archivo
	}

    // Declaración de nuevo vector bitácora
    vector<vector<string>> nuevaBitac;
    for (int j = 0; j < i; j++){
        vector<string> nuevaLinea;
        nuevaLinea.insert(nuevaLinea.end(), { mesVec[j], diaVec[j], horaVec[j], idVec[j], razonVec[j] });
        nuevaBitac.push_back(nuevaLinea);
    }
    
    //Obtener valor de IP
    vector<double> copia;
    copia = BST::copiaIp(nuevaBitac);
    
    //Creación del árbol
    BST tree, *root = nullptr;
    root = tree.insert(root, copia[0]);
    for (int z = 1; z < i; z++){
        tree.insert(root, copia[z]);
    }

    cout << "IPs con más accesos:" << endl;
   
    tree.inorden(root);
    
    return 0;
    
}