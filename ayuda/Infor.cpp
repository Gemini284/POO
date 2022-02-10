#include "Infor.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

Infor::~Infor()
{
}

Infor::Infor() {
}

Infor::Infor(string linea) {
    this->mes = linea.substr(0,3);
    this->dia = linea.substr(4,2);
    this->horas = linea.substr(7,2);
    this->minutos = linea.substr(10,2);
    this->segundos = linea.substr(13,2);
    this->ip = linea.substr(16, linea.find(" ", 16) - 16);
    this->mensaje = linea.substr(17 + ip.length(), linea.find("\n"));
        
    dateStruct.tm_sec = stoi(segundos);
    dateStruct.tm_min = stoi(minutos);
    dateStruct.tm_hour = stoi(horas);
    dateStruct.tm_mday = stoi(dia);
    for (int i{0} ; i < 12 ; i++) {
        if (meses[i] == mes)
            dateStruct.tm_mon = i;
    }
    dateStruct.tm_year = 2021 - 1900;
    valor = mktime(&dateStruct);
    
}

Infor::Infor(const Infor &other) {
        this->dateStruct = other.dateStruct;
        this->valor = other.valor;
        this->mes = other.mes;
        this->dia = other.dia;
        this->horas = other.horas;
        this->minutos = other.minutos;
        this->segundos = other.segundos;
        this->ip = other.ip;
        this->mensaje = other.mensaje;
}

time_t Infor::getDate() {
    return valor;
}

void Infor::print(ofstream &archivorden) {
    cout << mes << " ";
    cout << dia << " ";
    cout << horas << ":";
    cout << minutos << ":";
    cout << segundos << " ";
    cout << ip << " ";
    cout << mensaje;
    
    archivorden << mes << " ";
    archivorden << dia << " ";
    archivorden << horas << ":";
    archivorden << minutos << ":";
    archivorden << segundos << " ";
    archivorden << ip << " ";
    archivorden << mensaje << endl;
}

bool Infor::operator==(const Infor &other) {
  return this->valor == other.valor;
}

bool Infor::operator==(const time_t &other) {
  return this->valor == other;
}

bool Infor::operator!=(const Infor &other) {
  return this->valor != other.valor;
}

bool Infor::operator>(const Infor &other) {
  return this->valor > other.valor;
}

bool Infor::operator<(const Infor &other) {
  return this->valor < other.valor;
}

bool Infor::operator>(const time_t &other) {
  return this->valor > other;
}

bool Infor::operator<=(const Infor &other) {
  return this->valor <= other.valor;
}

