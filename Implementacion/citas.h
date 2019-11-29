#ifndef CITAS_H
#define CITAS_H


class Cita{
  private:
    string hora_,DNI_;
    int dia_,mes_,anyo_;
  public:
    Citas(string DNI,string hora,int dia,int mes,int anyo){DNI_=DNI; hora_=hora; dia_=dia; mes_=mes; anyo_=anyo};

    inline string  getDNI () const {return DNI_;};
		inline void setDNI(string DNI){DNI_=DNI;};
    
    inline int getHora() {return hora_;};
    inline void setHora(int hora){hora_=hora;};

    inline int getDia() {return dia_;};
    inline void setDia(int dia){dia_=dia;};

    inline int getMes() {return mes_;};
    inline void setMes(int mes){mes_=mes;};

    inline int getAnyo() {return anyo_;};
    inline void setAnyo(int anyo){anyo_=anyo;};


};



#endif
