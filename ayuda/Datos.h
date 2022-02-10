#ifndef IP_H
#define IP_H
#include <iostream>
#include <fstream>
#include <ctime>//Literalmente regresa datos de tiempo en texto
#include <algorithm>
#include <vector>
using namespace std;

class Datos {
private: 
        struct tm dateStruct;
        time_t valor;
        string mes;
        string dia;
        string horas;
        string minutos;
        string segundos;
        string ip;
        string mensaje;
        vector<string> meses{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
        Datos();
        Datos(string);
        Datos(const Datos&);
        time_t getDate();
        void print(ofstream&);
        bool operator ==(const Datos&);
        bool operator ==(const time_t&);
        bool operator !=(const Datos&);
        bool operator >(const Datos&);
        bool operator <(const Datos&);
        bool operator >(const time_t&);
        bool operator <=(const Datos&);
        ~Datos();

};

#endif