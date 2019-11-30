/*
 ___________________________________________________________________
|                                                                   |
| Proyecto Ingenieria del Software Universidad de Cordoba 2019/2020 |
|___________________________________________________________________|

                            PROGRAMADORES
                  -------------------------------------
                        Cristian Gonzalez Ortiz
                        Youness Bettahi Berdai
                        Manuel de la Cueva Coca
                  -------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include "paciente.h"
#include "programa.h"
#include "citas.h"

using namespace std;
/*Este es el archivo principal donde se llama a todas las funciones del Programa
Consta del menu de opciones que refleja todos los requisitos funcionales que soporta nuestro software*/

int main(){

  int opcion;
  Programa pr;
  Paciente pa("4663263","Cristian","Gonzalez");
  Cita ci("12345678","00:00",17,11,2000);
  string nombre,apellidos,DNI,PublicaPrivada,telefono,hora;
  int codigoPostal,dia,mes,anyo;

  do{

    //system("clear");
    cout<<"\t ___________________________________________________"<<endl;
    cout<<"\t|                                                   |"<<endl;
    cout<<"\t|\t\t______CLINICA______                 |"<<endl;
    cout<<"\t|  -----------------------------------------------  |"<<endl;
    cout<<"\t|\t1.Mostar citas del dia.                     |"<<endl;
    cout<<"\t|  -----------------------------------------------  |"<<endl;
    cout<<"\t|\t\t______PACIENTES______               |"<<endl;
    cout<<"\t|  -----------------------------------------------  |"<<endl;
    cout<<"\t|\t2.Mostrar pacientes actuales.               |"<<endl;
    cout<<"\t|\t3.Dar de alta a un nuevo paciente.          |"<<endl;
    cout<<"\t|\t4.Modificar datos de un paciente.           |"<<endl;
    cout<<"\t|\t5.Buscar paciente por dni.                  |"<<endl;
    cout<<"\t|\t6.Borrar paciente.                          |"<<endl;
    cout<<"\t|  -----------------------------------------------  |"<<endl;
    cout<<"\t|\t\t______CITAS______                   |"<<endl;
    cout<<"\t|  -----------------------------------------------  |"<<endl;
    cout<<"\t|\t7.Mostrar citas.                            |"<<endl;
    cout<<"\t|\t8.Nueva cita.                               |"<<endl;
    cout<<"\t|\t9.Cancelar cita.                            |"<<endl;
    cout<<"\t|\t10.Cerrar sesion.                           |"<<endl;
    cout<<"\t|___________________________________________________|"<<endl;

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
                cout<<"\n\nYa hay un paciente con ese DNI registrado\n\n\n"<<endl;
              }
              else{
                cout<<"\n\nPaciente registrado con exito\n\n\n"<<endl;
              }
              pr.escribePacientes();
    break;

      case 4: system("clear");
    break;

      case 5: system("clear");
              cout<<"Introduzca el DNI del paciente que quiere buscar:";
              cin>>DNI;
              pr.mostrarDatos(DNI);
    break;

      case 6: system("clear");
    break;

      case 7: system("clear");
    break;

      case 8: system("clear");
          if(pr.buscarPaciente(ci.getDni())==true){
              fflush(stdin);
              cout<<"Introduce la hora de la cita:";
              cin>>hora;
              ci.setHora(hora);
              cin.ignore();
              cout<<"Introduce el dia de la cita:";
              cin>>dia;
              ci.setDia(dia);
              cin.ignore();
              cout<<"Introduce el mes de la cita:";
              cin>>mes;
              ci.setMes(mes);
              cin.ignore();
              cout<<"Introduce el anyo de la cita:";
              cin>>anyo;
              ci.setAnyo(anyo);
              cin.ignore();
              pr.addCitas(&ci);
          }


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
