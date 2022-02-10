/*Este programa recibe información de fechas de un archivo de texto, la convierte en un vector de clase Infor,
la ordena de más antiguo a reciente, y solicita dos fechas para imprimir todas las fechas dentro de esos dos valores.

Tambien utiliza una doubly linked list con stack para realizar su sorteo.

Escrito por: 
-Diego Kury Rivera A00227097

Creado el 7 de octubre de 2021
Última modificación: 15 de octubre de 2021*/

#include "Infor.hpp"
#include "DoubleLinkedList.hpp"
#include "Stack.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

time_t getDate(string fecha) { 
    
    vector<string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    struct tm dateStruct;
    
    string mes{fecha.substr(0,fecha.find(" "))};
    int dia{stoi(fecha.substr(3,fecha.find(" ")))};
    int horas{stoi(fecha.substr(6,fecha.find(":")))};
    int minutos{stoi(fecha.substr(10,fecha.find(":")))};
    int segundos{stoi(fecha.substr(13,fecha.find(":")))};

    dateStruct.tm_sec = segundos;
    dateStruct.tm_min = minutos;
    dateStruct.tm_hour = horas;
    dateStruct.tm_mday = dia;
    
    for (size_t i{0} ; i < 12 ; i++){
        if (meses[i] == mes)
            dateStruct.tm_mon = i;
    }
    dateStruct.tm_year = 2021 - 1900;
    
    return mktime(&dateStruct);
}

int binarySearch(vector<Infor> &values, int n, time_t k) {
    int low{0};
    int high{n - 1};
    while (low <= high) {
    int m{low + (high - low) / 2};
        if (values[m] == k) 
            return m;
        else if (values[m] > k) 
            high = m - 1;
        else 
            low = m + 1;
    }
    return -1;
}

int main() {

    vector<Infor> infTotal;

    string nomArch{"bitacora.txt"};
    ifstream archivo(nomArch.c_str());
    string linea{};
    while (getline(archivo, linea))
        infTotal.push_back(Infor(linea));
        
    //Conversión de vector de Infor a Nodo
    DoubleLinkedList<Infor> infNode;
    for (long long unsigned int i{0} ; i < infTotal.size() ; i++)
        infNode.addLast(infTotal.at(i));
    
    //Sorteo de información a través de Quick Sort
    infNode.quickSortIterative();
    
    //Reacomodación en vector de Infor
    vector<Infor> infTotalSort;
    for (long long unsigned int i{0} ; i < infTotal.size() ; i++)
        infTotalSort.push_back(infNode.getData(i));
    
    //mergeSort(infTotal, 0, infTotal.size() - 1);
    
    int fechai{}, fechaf{};
    string fecha{};
    cout << "Fecha Inicial: " << endl;
    getline(cin, fecha); 
    fechai = getDate(fecha);

    cout << "Fecha Final: " << endl;
    getline(cin, fecha); 
    fechaf = getDate(fecha);
    
    int ipos{}, fpos{};
    ipos = binarySearch(infTotalSort, infTotalSort.size(), fechai);
    fpos = binarySearch(infTotalSort, infTotalSort.size(), fechaf);
    
    ofstream archivorden ("ponmecien.txt");
    for (int i{ipos} ; i <= fpos ; i++) {
        infTotalSort[i].print(archivorden);
        cout << endl;
    } 
    
    archivorden.close();
    return 0;
}

//No se como logré escribir esto jajajaj que relajo de código, saludos profe
