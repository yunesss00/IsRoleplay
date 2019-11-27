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
		fichero<<i->getDNI()+",";
		fichero<<i->getNombre()+",";
		fichero<<i->getApellidos()+",";
		fichero<<i->getTelefono()+",";
		fichero<<i->getPublicaPrivada()+",";
		fichero<<i->getCodigoPostal()<<endl;
	}
	fichero.close();
}