#include "MyHashTable.h"
#include <iostream>

using namespace std;

int main(){
    MyHashTable alumnos;
    alumnos.put("Oscar",1638923);
    alumnos.put("Emma",1740229);
    alumnos.put("Santiago",1640329);
    alumnos.put("John Paul",1639913);
    alumnos.put("Ariadna",1639943);
    alumnos.remove("Santiago");

    string nombre = "Oscar";
    cout<< "La matricula de "<< nombre << " es " << alumnos.get(nombre) << endl;
    nombre = "Emma";
    cout<< "La matricula de "<< nombre << " es " << alumnos.get(nombre) << endl;
    nombre = "Santiago";
    cout<< "La matricula de "<< nombre << " es " << alumnos.get(nombre) << endl;
    nombre = "John Paul";
    cout<< "La matricula de "<< nombre << " es " << alumnos.get(nombre) << endl;
    nombre = "Ariadna";
    cout<< "La matricula de "<< nombre << " es " << alumnos.get(nombre) << endl;
}
