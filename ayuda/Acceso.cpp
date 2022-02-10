//
//  Acceso.cpp
//  Proyecto2
//
//  Created by Manuel Cardenas on 10/10/21.
//

#include <iostream>
using namespace std;

# include "Acceso.h"

Acceso::Acceso(){
    this->mes = "Null";
    this->dia = 0;
    this->hora = "Null";
    this->ipA = this->ipB = this->ipC = this->ipD = this->puerto = 0;
    this->error = "Null";
}

Acceso::Acceso(string mes, int dia, string hora, int ipA, int ipB, int ipC, int ipD, int puerto, string error){
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->ipA = ipA;
    this->ipB = ipB;
    this->ipC = ipC;
    this->ipD = ipD;
    this->puerto = puerto;
    this->error = error;
}


//Getters
string Acceso::getMes(){
    return this->mes;
}

int Acceso::getDia(){
    return this->dia;
}

string Acceso::getHora(){
    return this->hora;
}

int Acceso::getIpA(){
    return this->ipA;
}

int Acceso::getIpB(){
    return this->ipB;
}

int Acceso::getIpC(){
    return this->ipC;
}

int Acceso::getIpD(){
    return this->ipD;
}

int Acceso::getPuerto(){
    return this->puerto;
}

string Acceso::getError(){
    return this->error;
}


//Setters
void Acceso::setMes(string mes){
    this->mes = mes;
}

void Acceso::setDia(int dia){
    this->dia = dia;
}

void Acceso::setHora(string hora){
    this->hora = hora;
}

void Acceso::setIpA(int ipA){
    this->ipA = ipA;
}

void Acceso::setIpB(int ipB){
    this->ipB = ipB;
}

void Acceso::setIpC(int ipC){
    this->ipC = ipC;
}

void Acceso::setIpD(int ipD){
    this->ipD = ipD;
}

void Acceso::setPuerto(int puerto){
    this->puerto = puerto;
}

void Acceso::setError(string error){
    this->error = error;
}


//Metodos
void Acceso::imprime(){
    cout << getMes() << " " << getDia() << " " << getHora() << " " << getIpA() << "." << getIpB() << "." << getIpC() << "." << getIpD() << ":" << getPuerto() << " " << getError() << endl;
}
