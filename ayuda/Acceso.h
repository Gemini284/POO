//
//  Acceso.h
//  Proyecto2
//
//  Created by Manuel Cardenas on 10/10/21.
//

#ifndef Acceso_h
#define Acceso_h

class Acceso{
    private:
        string mes;
        int dia;
        string hora;
        int ipA;
        int ipB;
        int ipC;
        int ipD;
        int puerto;
        long long int ipAndPuerto;
        string error;
    public:
        Acceso();
        Acceso(string, int, string, int, int, int, int, int, string);
        //Getters
        string getMes();
        int getDia();
        string getHora();
        int getIpA();
        int getIpB();
        int getIpC();
        int getIpD();
        int getPuerto();
        string getError();
        //Setters
        void setMes(string);
        void setDia(int);
        void setHora(string);
        void setIpA(int);
        void setIpB(int);
        void setIpC(int);
        void setIpD(int);
        void setPuerto(int);
        void setError(string);
        //Metodos
        void imprime();
};

#endif /* Acceso_h */
