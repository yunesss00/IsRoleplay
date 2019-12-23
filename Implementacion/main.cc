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
  int op;
  int opcion;
  Programa pr;
  Paciente pa("4663263","Cristian","Gonzalez");
  Cita ci("12345678","00:00",17,11,2000);
  string nombre,apellidos,apellido1,apellido2,DNI,PublicaPrivada,telefono,hora;
  int codigoPostal,dia,mes,anyo;

  do{

    //system("clear");
    cout<<endl;
    cout<<"\t ___________________________________________________"<<endl;
    cout<<"\t|                                                   |"<<endl;
    cout<<"\t|               ______CLINICA______                 |"<<endl;
    cout<<"\t|  -----------------------------------------------  |"<<endl;
    cout<<"\t|       1.Mostar citas del dia.                     |"<<endl;
    cout<<"\t|  -----------------------------------------------  |"<<endl;
    cout<<"\t|               ______PACIENTES______               |"<<endl;
    cout<<"\t|  -----------------------------------------------  |"<<endl;
    cout<<"\t|       2.Mostrar pacientes actuales.               |"<<endl;
    cout<<"\t|       3.Dar de alta a un nuevo paciente.          |"<<endl;
    cout<<"\t|       4.Modificar datos de un paciente.           |"<<endl;
    cout<<"\t|       5.Buscar paciente por dni.                  |"<<endl;
    cout<<"\t|       6.Borrar paciente.                          |"<<endl;
    cout<<"\t|  -----------------------------------------------  |"<<endl;
    cout<<"\t|               ______CITAS______                   |"<<endl;
    cout<<"\t|  -----------------------------------------------  |"<<endl;
    cout<<"\t|       7.Mostrar citas.                            |"<<endl;
    cout<<"\t|       8.Nueva cita.                               |"<<endl;
    cout<<"\t|       9.Cancelar cita.                            |"<<endl;
    cout<<"\t|  -----------------------------------------------  |"<<endl;
    cout<<"\t|       10.Añadir Historia Clínica.                 |"<<endl;
    cout<<"\t|       11.Cerrar sesion.                           |"<<endl;
    cout<<"\t|___________________________________________________|"<<endl;

    cout<<"\nElige una opcion:"<<endl;
    cin>>opcion;

    switch(opcion){
      case 1: system("clear");
              ci.mostrarCitas();
    break;

      case 2: system("clear");
              pr.mostrarPacientes();
    break;

      case 3: system("clear");
              cout<<"Introduce los datos del paciente"<<endl;
              cout<<"(Si tiene un nombre o un apellido compuesto, escríbalo sin espacios) "<<endl;
              cout<<"Nombre: ";
              cin>>nombre;
              pa.setNombre(nombre);
              cout<<"Apellido1: ";
              cin>>apellido1;
              cout<<"Apellido2: ";
              cin>>apellido2;
              apellidos=apellido1+","+apellido2;
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
              cout<<"Introduzca el DNI del paciente al que le quiere modificar algun dato:";
              cin>>DNI;
              if(pr.buscarPaciente(DNI)==true){
              	pr.menuModificar(DNI);}
              
    break;

      case 5: system("clear");
              cout<<"Introduzca el DNI del paciente que quiere buscar:";
              cin>>DNI;
              pr.mostrarDatos(DNI);
               if(pr.buscarPaciente(DNI)==true){
              cout<<"¿Desea acceder a la historia clinica del paciente?"<<endl;
              cout<<"Introduzca [0] para acceder"<<endl;
              cout<<"Introduzca [1] para salir"<<endl;
              cin>>op;
              if(op==0){
              	pr.mostrarHistoria(DNI);
              }
              }
    break;

      case 6: system("clear");
              cout<<"Introduzca el DNI del paciente que desea borrar:";
              cin>>DNI;
              if(pr.buscarPaciente(DNI)==true){
                  pr.borrarPaciente(DNI);
              }
    break;

      case 7: system("clear");
              ci.mostrarCitasTotales();
    break;

      case 8: system("clear");
              cout<<"Introduce el DNI del paciente:";
              cin>>DNI;
              ci.setDNI(DNI);
              if(pr.buscarPaciente(DNI)==true){
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

                if(pr.buscarCita(ci)==false){
                   pr.addCitas(ci);
                   pr.escribeCitas();
                }

              }else{
                cout<<"Este DNI no se encuentra registrado en la base de datos."<<endl;
              }


    break;

      case 9: system("clear");
              cout<<"Introduce el DNI del paciente:";
              cin>>DNI;
              ci.setDNI(DNI);
              if(pr.buscarPaciente(DNI)==true){
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
                ci.cancelarCita(ci);
              }
              else{
                cout<<"Este DNI no se encuentra registrado en la base de datos."<<endl;
              }
    break;

 case 10: system("clear");

     cout<<"Introduzca el DNI del paciente al que desea añadir una historia clinica:";
              cin>>DNI;
              if(pr.buscarPaciente(DNI)==true){
                  pr.anadirHistoria(DNI);
              }
              break;

 case 11: system("clear");
		cout<<"Saliendo del programa..."<<endl;

		exit(-1);

     
              break;

      default: cout<<"No existe esta opcion."<<endl;
    }

  }while(opcion>=1 && opcion<=11);




  return 0;
}
