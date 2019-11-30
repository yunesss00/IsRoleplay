#include <iostream>
#include <cstdlib>
#include <string>
#ifndef CITAS_H
#define CITAS_H



class Cita{
  private:
    string hora_;
    int dia_,mes_,anyo_;
  public:
    Cita(string hora,int dia,int mes,int anyo){hora_=hora; dia_=dia; mes_=mes; anyo_=anyo;};

    inline string getHora() {return hora_;};
    inline void setHora(string hora){hora_=hora;};

    inline int getDia() {return dia_;};
    inline void setDia(int dia){dia_=dia;};

    inline int getMes() {return mes_;};
    inline void setMes(int mes){mes_=mes;};

    inline int getAnyo() {return anyo_;};
    inline void setAnyo(int anyo){anyo_=anyo;};


};



#endif
