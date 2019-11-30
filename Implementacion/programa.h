#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "paciente.h"
#include "citas.h"
#include <list>
using namespace std;

/*La clase programa que es donde se encuentran todos los prototipos de los requisitos funcionales que se esperan,
así como los atributos globales que se podran utlizar en las demas clases*/
class Programa {
	private:
		list <Paciente> pacientes_;

	public:
		bool addPaciente(Paciente paciente);
		void escribePacientes();

		bool buscarPaciente(string DNI);
		bool mostrarDatos(string DNI);

		void addCitas(Cita *cita);




};



























#endif
