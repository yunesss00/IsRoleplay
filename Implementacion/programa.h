#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "paciente.h"
#include <list>
using namespace std;

class Programa {
	private:
		list <Paciente> pacientes_;

	public:
		bool addPaciente(Paciente paciente);
		void escribePacientes();




};



























#endif