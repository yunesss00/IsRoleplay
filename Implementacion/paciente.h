#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>
#include <list>

using namespace std;


class Paciente{
  private:
    string nombre_, apellidos_,publicaPrivada_,DNI_;
    string telefono_;
    int codigoPostal_;

  public:
    Paciente(string dni, string nombre, string apellidos, string telefono="", string publicaPrivada=" ", int codigoPostal=0){DNI_=dni; nombre_=nombre; apellidos_=apellidos; codigoPostal_=codigoPostal; publicaPrivada_=publicaPrivada; telefono_=telefono;};

    	inline string  getDNI () const {return DNI_;};
		inline void setDNI(string DNI){DNI_=DNI;};

		inline string  getNombre () const {return nombre_;};
		inline void setNombre(string nombre){nombre_=nombre;};

		inline string  getApellidos () const {return apellidos_;};
		inline void setApellidos(string apellidos){apellidos_=apellidos;};

		inline string  getTelefono() const {return telefono_;};
		inline void setTelefono(string telefono){telefono_=telefono;};

		inline string getPublicaPrivada() const {return publicaPrivada_;};
		inline void setPublicaPrivada(string publicaPrivada){publicaPrivada_=publicaPrivada;};

		inline int getCodigoPostal() const{return codigoPostal_;};
		inline void setCodigoPostal(int codigoPostal){codigoPostal_=codigoPostal;};



};




#endif
