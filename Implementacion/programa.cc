/*En programa.cc se encuentran todas las funciones que son llamadas de la main,
aqui es donde estan todos los requisitos funcionales  del programa*/
#include <iostream>
#include <cstdlib>
#include <string>
#include "paciente.h"
#include "programa.h"
#include <list>
#include <fstream>
using namespace std;

//La funcion añadir paciente
bool Programa::addPaciente(Paciente paciente){
	list <Paciente>::iterator i;
/*Recorre el fichero .txt y busca concordancia en el dni para saber si ya existe el paciente,
si lo encuentra, retorna false*/
if(buscarPaciente(paciente.getDNI())==true){
	return false;
}
	//Si no encuentra el dni, sigue la ejecucion de la funcion y crea el fichero paciente.txt si no existe previamente
	pacientes_.push_back(paciente);
	string nomfich="Pacientes.txt";
	ifstream fich(nomfich.c_str());

	if(!fich){
		ofstream(nomfich.c_str());
	}

	fich.close();
	return true;
}

//Escribe los pacientes en el fichero de texto pacientes.txt con el siguente formato, si existe el fichero añade informacion sin borrar lo anterior
void Programa::escribePacientes(){
	list <Paciente>::iterator i;
	fstream fichero;
	fichero.open("Pacientes.txt",ios::app);
	for(i=pacientes_.begin();i!=pacientes_.end();i++){
		fichero<<"DNI:"<<i->getDNI()+"\n";
		fichero<<"Nombre:"<<i->getNombre()+"\n";
		fichero<<"Apellidos:"<<i->getApellidos()+"\n";
		fichero<<"Telefono:"<<i->getTelefono()+"\n";
		fichero<<"Seguridad:"<<i->getPublicaPrivada()+"\n";
		fichero<<"CodigoPostal:"<<i->getCodigoPostal()<<endl;
	}
	fichero.close();
}

/*Esta funcion busca dentro del fichero .txt mediante dni si extste alguna coincidencia
y a continuacion proporciona todos los daatos relacionados al paciente*/
bool Programa::buscarPaciente(string DNI){
	fstream fichPacientes;
	string linea,linea2,linea3,linea4,linea5,linea6;
	int validacion=0;
	string menu;

	if(!fichPacientes.is_open()){
		fichPacientes.open("Pacientes.txt",ios::in);
	}

	while(getline(fichPacientes,linea)){
		if(linea.find(DNI)!=string::npos){
			validacion=1;
			cout<<"\n\n";
			return true;
		}
	}

	fichPacientes.close();

	if(validacion==0){
		cout<<"No se ha encontrado un paciente con un DNI coincidente"<<endl;
		return false;
	}else{
		cout<<"Exito al encontrar el paciente"<<endl;
	}

	cout<<"Pulse cualquier tecla para volver al menu principal...\n";
	cin>>menu;
}

bool Programa::mostrarDatos(string DNI){
	fstream fichPacientes;
	string linea,linea2,linea3,linea4,linea5,linea6;
	int validacion=0;
	string menu;

	if(!fichPacientes.is_open()){
		fichPacientes.open("Pacientes.txt",ios::in);
	}

	while(getline(fichPacientes,linea)){
		if(linea.find(DNI)!=string::npos){
			cout<<"\nMostrando datos...\n";
			cout<<linea<<endl;
			getline(fichPacientes,linea2);
			cout<<linea2<<endl;
			getline(fichPacientes,linea3);
			cout<<linea3<<endl;
			getline(fichPacientes,linea4);
			cout<<linea4<<endl;
			getline(fichPacientes,linea5);
			cout<<linea5<<endl;
			getline(fichPacientes,linea6);
			cout<<linea6<<endl;
			validacion=1;
			cout<<"\n\n";
			return true;
		}
	}

	fichPacientes.close();

	if(validacion==0){
		cout<<"No se ha encontrado un paciente con un DNI coincidente"<<endl;
		return false;
	}else{
		cout<<"Exito al encontrar el paciente"<<endl;
	}

	cout<<"Pulse cualquier tecla para volver al menu principal...\n";
	cin>>menu;
}

void Programa::addCitas(Cita cita){
	list <Cita>::iterator i;
	citas_.push_back(cita);
	string nomfich = "Citas.txt";
	ifstream fich(nomfich.c_str());

	if(!fich){
		ofstream(nomfich.c_str());
	}
	fich.close();
}

void Programa::escribeCitas(){
	list <Cita>::iterator i;
	fstream fichCitas;
	fichCitas.open("Citas.txt",ios::app);
	for(i=citas_.begin();i!=citas_.end();i++){
		fichCitas<<"Paciente:"<<i->getDNI();
		fichCitas<<" Hora:"<<i->getHora();
		fichCitas<<" Dia:"<<i->getDia();
		fichCitas<<" Mes:"<<i->getMes();
		fichCitas<<" Anyo:"<<i->getAnyo()<<endl;
	}

	fichCitas.close();
	cout<<"\n\n\n\n\n";
}
