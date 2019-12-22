#include "citas.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "paciente.h"
#include "programa.h"
#include <list>
#include <fstream>
#include <ctime>
#include <vector>
#include <cstring>
using namespace std;


/*	struct tm {
		int tm_sec //seconds of minutes from 0 to 61
		int tm_min //minutes of hour from 0 to 59
		int tm_hour // hours of day from 0 to 24
		int tm_mday //day of month from 1 to 31
		int tm_mon // month of year from 0 to 11
		int tm_year // year since 1900
		int tm_wday // days since sunday
		int tm_yday // days since January 1st
		int tm_isdst // hours of daylight savings time
	};*/



void Cita::mostrarCitas(){
	fstream fichCitas;
	fichCitas.open("Citas.txt",ios::in);
	time_t now = time(0);
	tm * time = localtime(&now);
	string paciente,hora,fecha;
	int anyo=1900 + time->tm_year;

	/*cout<<"Estamos a dia "<<time->tm_mday;
	cout<<" Mes "<<time->tm_mon+1;
	cout<<" Year "<<anyo;
	cout<<" Hora "<<time->tm_hour<<":"<<time->tm_min<<":"<<time->tm_sec;*/

	if(!fichCitas.is_open()){
		fichCitas.open("Citas.txt",ios::in);
	}

	int dia=time->tm_mday;
	int mes=time->tm_mon+1;
	string dias= std::to_string(dia);
	string mess= std::to_string(mes);
	string anyos=std::to_string(anyo);
	string combo=dias+"/"+mess+"/"+anyos;
	while(!fichCitas.eof()){
		fichCitas>>paciente>>hora>>fecha;
		if(fecha==combo){
			cout<<paciente<<" "<<hora<<" "<<fecha<<endl;
		}
		
	}
	

	fichCitas.close();

}

void Cita::mostrarCitasTotales(){
	fstream fichCitas;
	fichCitas.open("Citas.txt",ios::in);
	string paciente,hora,fecha;


	if(!fichCitas.is_open()){
		fichCitas.open("Citas.txt",ios::in);
	}

	while(!fichCitas.eof()){
		fichCitas>>paciente>>hora>>fecha;
		cout<<paciente<<" "<<hora<<" "<<fecha<<endl;
	}

	fichCitas.close();


}

void Cita::cancelarCita(Cita aux){
	fstream fichCitas;
	fichCitas.open("Citas.txt",ios::in);
	string paciente,hora,fecha;
	ofstream temporal;
	temporal.open("temporal.txt",ios::out);

	if(!fichCitas.is_open()){
		fichCitas.open("Citas.txt",ios::in);
	}

	string buscaPaciente="Paciente:"+aux.getDNI();
	string buscaHora="Hora:"+aux.getHora();
	string dias=std::to_string(aux.getDia());
	string meses=std::to_string(aux.getMes());
	string anyos=std::to_string(aux.getAnyo());
	string fechabuscar=dias+"/"+meses+"/"+anyos;
	while(!fichCitas.eof()){
		fichCitas>>paciente>>hora>>fecha;
		if((buscaPaciente==paciente)&&(buscaHora==hora)&&(fechabuscar==fecha)){
			cout<<"Cita borrada con exito."<<endl;
		}
		else{
			temporal<<paciente<<" "<<hora<<" "<<fecha+"\n";
		}
	}

	fichCitas.close();
	temporal.close();

	remove("Citas.txt");
	rename("temporal.txt","Citas.txt");
}