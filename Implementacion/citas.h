#ifndef CITAS_H
#define CITAS_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
//La clase cita que recoge y proporciona los datos relacionados a las citas
class Cita{
  private:
    string hora_,DNI_;
    int dia_,mes_,anyo_;
  public:
    Cita(string DNI,string hora,int dia,int mes,int anyo){DNI_=DNI; hora_=hora; dia_=dia; mes_=mes; anyo_=anyo;};

    inline string getDNI() {return DNI_;};
    inline void setDNI(string DNI){DNI_=DNI;};

    inline string getHora() {return hora_;};
    inline void setHora(string hora){hora_=hora;};

    inline int getDia() {return dia_;};
    inline void setDia(int dia){dia_=dia;};

    inline int getMes() {return mes_;};
    inline void setMes(int mes){mes_=mes;};

    inline int getAnyo() {return anyo_;};
    inline void setAnyo(int anyo){anyo_=anyo;};

    void mostrarCitas();
    void mostrarCitasTotales();
    void cancelarCita(Cita aux);


};



#endif
