#include <iostream>
#include <cstdlib>
#include <string>
#include "paciente.h"
#include "programa.h"
//#include "citas.h"

using namespace std;


int main(){

  int opcion;
  Programa pr;
  Paciente pa("4663263","Cristian","Gonzalez");
  //Cita ci("00:00",17,11,2000);
  string nombre,apellidos,DNI,PublicaPrivada,telefono/*,hora*/;
  int codigoPostal/*,dia,mes,anyo*/;

  do{

    //system("clear");
    cout<<"\t______CLINICA______"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"1.Mostar citas del dia."<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"\t______PACIENTES______"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"2.Mostrar pacientes actuales."<<endl;
    cout<<"3.Dar de alta a un nuevo paciente."<<endl;
    cout<<"4.Modificar datos de un paciente."<<endl;
    cout<<"5.Buscar paciente por dni."<<endl;
    cout<<"6.Borrar paciente."<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"\t______CITAS______"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"7.Mostrar citas."<<endl;
    cout<<"8.Nueva cita."<<endl;
    cout<<"9.Cancelar cita."<<endl;
    cout<<"10.Cerrar sesion."<<endl;

    cout<<"\nElige una opcion:"<<endl;
    cin>>opcion;

    switch(opcion){
      case 1: system("clear");
    break;

      case 2: system("clear");
    break;

      case 3: system("clear");
              cout<<"Introduce los datos del paciente"<<endl;
              cout<<"Nombre: ";
              cin>>nombre;
              pa.setNombre(nombre);
              cout<<"Apellidos: ";
              cin>>apellidos;
              pa.setApellidos(apellidos);
              cout<<"DNI: ";
              cin>>DNI;
              pa.setDNI(DNI);
              cout<<"Publica o Privada: ";
              cin>>PublicaPrivada;
              pa.setPublicaPrivada(PublicaPrivada);
              cout<<"Telefono: ";
              cin>>telefono;
              pa.setTelefono(telefono);
              cout<<"Codigo postal: ";
              cin>>codigoPostal;
              cout<<"prueba1"<<endl;
              pa.setCodigoPostal(codigoPostal);
              cout<<"prueba2"<<endl;
              if(pr.addPaciente(pa)==false){
                cout<<"Ya hay un paciente con ese DNI registrado"<<endl;
              }
              else{
                cout<<"Paciente registrado con exito"<<endl;
              }
              pr.escribePacientes();
    break;

      case 4: system("clear");
    break;

      case 5: system("clear");
              pr.buscarPaciente();
    break;

      case 6: system("clear");
    break;

      case 7: system("clear");
    break;

      case 8: system("clear");
              /*cout<<"Introduce el dni del paciente:";
              cin>>DNI;
              cout<<"Introduce la hora de la cita:";
              cin>>hora;
              ci.setHora(hora);
              cout<<"Introduce el dia de la cita:";
              cin>>dia;
              ci.setDia(dia);
              cout<<"Introduce el mes de la cita:";
              cin>>mes;
              ci.setMes(mes);
              cout<<"Introduce el anyo de la cita:";
              cin>>anyo;
              ci.setAnyo(anyo);
              if(pr.addCitas(ci,DNI)==false){
                cout<<"No existe ningun paciente con ese DNI introducido."<<endl;
              }
              else{
                cout<<"Cita registrada con exito."<<endl;
              }*/
    break;

      case 9: system("clear");
    break;

      case 10: system("clear");
    break;

      default: cout<<"No existe esta opcion."<<endl;
    }

  }while(opcion>=1 && opcion<=10);




  return 0;
}
