#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "paciente.h"
//#include "citas.h"
#include <list>
using namespace std;

class Programa {
	private:
		list <Paciente> pacientes_;
	//	list <Cita> citas_;

	public:
		bool addPaciente(Paciente paciente);
		void escribePacientes();

		bool buscarPaciente();

		//bool addCitas(Cita cita, string dni);
		//void escribeCitas();




};



























#endif
