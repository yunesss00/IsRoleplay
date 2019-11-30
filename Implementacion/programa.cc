#include <iostream>
#include <cstdlib>
#include <string>
#include "paciente.h"
#include "programa.h"
#include <list>
#include <fstream>
using namespace std;

bool Programa::addPaciente(Paciente paciente){
	list <Paciente>::iterator i;

	for(i=pacientes_.begin();i!=pacientes_.end(); i++){
		if(i->getDNI()==paciente.getDNI()){
			return false;
		}
	}
	pacientes_.push_back(paciente);
	string nomfich="Pacientes.txt";
	ifstream fich(nomfich.c_str());

	if(!fich){
		ofstream(nomfich.c_str());
	}

	fich.close();
	return true;
}

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

bool Programa::buscarPaciente(){
	fstream fichPacientes;
	string DNI,linea,linea2,linea3,linea4,linea5,linea6;
	int validacion=0;
	string menu;

	cout<<"Introduzca el DNI del paciente que quiere buscar:\n";
	cin>>DNI;

	if(!fichPacientes.is_open()){
		fichPacientes.open("Pacientes.txt",ios::in);
	}

	while(getline(fichPacientes,linea)){
		if(linea.find(DNI)!=string::npos){
			cout<<"Exito al encontrar el paciente"<<endl;
			cout<<"Mostrando datos...\n";
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
	}

	cout<<"Pulse cualquier tecla para volver al menu principal...\n";
	cin>>menu;



}

void Programa::addCitas(Cita *cita){
	fstream fichCitas;
	if(!fichCitas.is_open()){
		fichCitas.open("Citas.txt",ios::app);
	}
	fichCitas<<"Hora:"<<cita->getHora()+"\n";
	fichCitas<<"Dia:"<<cita->getDia()+"\n";
	fichCitas<<"Mes:"<<cita->getMes()+"\n";
	fichCitas<<"Anyo:"<<cita->getAnyo()<<endl;

	fichCitas.close();
	cout<<"\n\n\n\n\n";
}



