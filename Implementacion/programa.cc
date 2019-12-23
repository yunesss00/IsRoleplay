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
	pacientes_.erase(pacientes_.begin(),pacientes_.end());
	fichero.close();
}

/*Esta funcion busca dentro del fichero .txt mediante dni si extste alguna coincidencia
y a continuacion proporciona todos los daatos relacionados al paciente*/
bool Programa::buscarPaciente(string DNI){

	string buscaDNI="DNI:"+DNI;
	fstream fichPacientes;
	string linea,linea2,linea3,linea4,linea5,linea6;
	int validacion=0;
	string menu;

	if(!fichPacientes.is_open()){
		fichPacientes.open("Pacientes.txt",ios::in);
	}

	while(getline(fichPacientes,linea)){
		if(linea==buscaDNI){
			validacion=1;
			cout<<"\n\n";
			
		}
	}

	fichPacientes.close();

	if(validacion==0){
		cout<<"No se ha encontrado un paciente con un DNI coincidente"<<endl;
		return false;
	}else{
		cout<<"Exito al encontrar el paciente"<<endl;
		return true;
	}

}

bool Programa::mostrarDatos(string DNI){
	string buscaDNI="DNI:"+DNI;
fstream fichPacientes;
string linea,linea2,linea3,linea4,linea5,linea6;
int validacion=0;
string menu;
fstream fichCitas;
fichCitas.open("Citas.txt",ios::in);
string searchpaciente="Paciente:"+DNI;
string paciente,hora,fecha;

if(!fichPacientes.is_open()){
fichPacientes.open("Pacientes.txt",ios::in);
}

while(getline(fichPacientes,linea)){
if(linea==buscaDNI){
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
cout<<"Citas de este paciente:"<<endl;
while(!fichCitas.eof()){
fichCitas>>paciente>>hora>>fecha;
if(searchpaciente==paciente){
cout<<paciente<<' '<<hora<<' '<<fecha<<endl;
}
}

}
}

fichPacientes.close();
fichCitas.close();

if(validacion==0){
return false;
}else{

cout<<"Exito al encontrar el paciente"<<endl;
return true;
}

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
	//fstream fichCitas2;
	fichCitas.open("Citas.txt",ios::app);
	//string buscahora,buscadia,buscames,buscaanyo,buscafecha;
	string paciente,hora,fecha;
	for(i=citas_.begin();i!=citas_.end();i++){
				fichCitas<<"Paciente:"<<i->getDNI();
				fichCitas<<" Hora:"<<i->getHora();
				fichCitas<<" "<<i->getDia()<<"/"<<i->getMes()<<"/"<<i->getAnyo()<<endl;
	}
	citas_.erase(citas_.begin(),citas_.end());
	fichCitas.close();
	cout<<"\n\n\n\n\n";

}

bool Programa::buscarCita(Cita cita){
	fstream fichCitas;
	fichCitas.open("Citas.txt",ios::in);
	string paciente,hora,fecha;
	if(!fichCitas.is_open()){
		fichCitas.open("Citas.txt",ios::in);
	}

	string buscarhora="Hora:"+cita.getHora();
	string budia=std::to_string(cita.getDia());
	string bumes=std::to_string(cita.getMes());
	string buanyo=std::to_string(cita.getAnyo());
	string buscarfecha=budia+"/"+bumes+"/"+buanyo;
	while(!fichCitas.eof()){
		fichCitas>>paciente>>hora>>fecha;
		if((hora==buscarhora)&&(fecha==buscarfecha)){
			cout<<"Esta hora ya esta ocupada. Pruebe otra\n";
			return true;
		}
	}
	fichCitas.close();
	return false;
	
}


void Programa::borrarPaciente(string aux){
	ifstream fichPacientes;
	fichPacientes.open("Pacientes.txt",ios::in);
	ofstream temporal;
	temporal.open("temporal.txt",ios::out);
	string linea,linea2,linea3,linea4,linea5,linea6;

	if(!fichPacientes.is_open()){
		fichPacientes.open("Pacientes.txt",ios::in);
	}

	while(getline(fichPacientes,linea)){
		if(linea.find(aux)!=string::npos){
			getline(fichPacientes,linea2);
			getline(fichPacientes,linea3);
			getline(fichPacientes,linea4);
			getline(fichPacientes,linea5);
			getline(fichPacientes,linea6);

			cout<<"Paciente borrado con exito\n";
		}
		else{
			getline(fichPacientes,linea2);
			getline(fichPacientes,linea3);
			getline(fichPacientes,linea4);
			getline(fichPacientes,linea5);
			getline(fichPacientes,linea6);

			temporal<<linea+"\n";
			temporal<<linea2+"\n";
			temporal<<linea3+"\n";
			temporal<<linea4+"\n";
			temporal<<linea5+"\n";
			temporal<<linea6+"\n";
		}


	}
	fichPacientes>>linea;
	fichPacientes.close();
	temporal.close();

	remove("Pacientes.txt");
	rename("temporal.txt","Pacientes.txt");


}


void Programa::modificarNombre(string DNI){
	string nomaux,ape,tele,seguridad,codigo,linea,nom;
	fstream fichPacientes;
	fichPacientes.open("Pacientes.txt",ios::in);
	fstream fichAux;
	fichAux.open("auxiliar.txt",ios::out);


	while(getline(fichPacientes,linea)){
		if(linea.find(DNI)!=string::npos){
			cout<<"Introduzca el nuevo nombre:"<<endl;
			cin>>nomaux;
			fichAux<<"DNI:"<<DNI<<endl;
			fichAux<<"Nombre:"<<nomaux<<endl;
			getline(fichPacientes,nom);
				getline(fichPacientes,ape);
				fichAux<<ape<<endl;
				getline(fichPacientes,tele);
				fichAux<<tele<<endl;
				getline(fichPacientes,seguridad);
				fichAux<<seguridad<<endl;
				getline(fichPacientes,codigo);
				fichAux<<codigo<<endl;

		}
		else{
			fichAux<<linea<<endl;
			getline(fichPacientes,nom);
			fichAux<<nom<<endl;
			getline(fichPacientes,ape);
			fichAux<<ape<<endl;
			getline(fichPacientes,tele);
			fichAux<<tele<<endl;
			getline(fichPacientes,seguridad);
			fichAux<<seguridad<<endl;
			getline(fichPacientes,codigo);
			fichAux<<codigo<<endl;
		}


	}
		fichPacientes.close();
		fichAux.close();
		remove("Pacientes.txt");
		rename("auxiliar.txt","Pacientes.txt");


}


void Programa::modificarApellidos(string DNI){
    
    cout<<"Introduzca Apellido1,Apellido2"<<endl;
	string apeaux,ape,tele,seguridad,codigo,linea,nom;
	fstream fichPacientes;
	fichPacientes.open("Pacientes.txt",ios::in);
	fstream fichAux;
	fichAux.open("auxiliar.txt",ios::out);

	while(getline(fichPacientes,linea)){
		if(linea.find(DNI)!=string::npos){
			cout<<"Introduzca el nuevo apellido:"<<endl;
			cin>>apeaux;
			fichAux<<"DNI:"<<DNI<<endl;
			getline(fichPacientes,nom);
			fichAux<<nom<<endl;
				getline(fichPacientes,ape);
				fichAux<<"Apellidos:"<<apeaux<<endl;
				getline(fichPacientes,tele);
				fichAux<<tele<<endl;
				getline(fichPacientes,seguridad);
				fichAux<<seguridad<<endl;
				getline(fichPacientes,codigo);
				fichAux<<codigo<<endl;

		}
		else{
			fichAux<<linea<<endl;
			getline(fichPacientes,nom);
			fichAux<<nom<<endl;
			getline(fichPacientes,ape);
			fichAux<<ape<<endl;
			getline(fichPacientes,tele);
			fichAux<<tele<<endl;
			getline(fichPacientes,seguridad);
			fichAux<<seguridad<<endl;
			getline(fichPacientes,codigo);
			fichAux<<codigo<<endl;
		}


	}
		fichPacientes.close();
		fichAux.close();
		remove("Pacientes.txt");
		rename("auxiliar.txt","Pacientes.txt");


}

void Programa::modificarTelefono(string DNI){
	string teleaux,ape,tele,seguridad,codigo,linea,nom;
	fstream fichPacientes;
	fichPacientes.open("Pacientes.txt",ios::in);
	fstream fichAux;
	fichAux.open("auxiliar.txt",ios::out);

	while(getline(fichPacientes,linea)){
		if(linea.find(DNI)!=string::npos){
			cout<<"Introduzca el nuevo telefono:"<<endl;
			cin>>teleaux;
			fichAux<<"DNI:"<<DNI<<endl;
			getline(fichPacientes,nom);
			fichAux<<nom<<endl;
				getline(fichPacientes,ape);
				fichAux<<ape<<endl;
				getline(fichPacientes,tele);
				fichAux<<"Telefono:"<<teleaux<<endl;
				getline(fichPacientes,seguridad);
				fichAux<<seguridad<<endl;
				getline(fichPacientes,codigo);
				fichAux<<codigo<<endl;

		}
		else{
			fichAux<<linea<<endl;
			getline(fichPacientes,nom);
			fichAux<<nom<<endl;
			getline(fichPacientes,ape);
			fichAux<<ape<<endl;
			getline(fichPacientes,tele);
			fichAux<<tele<<endl;
			getline(fichPacientes,seguridad);
			fichAux<<seguridad<<endl;
			getline(fichPacientes,codigo);
			fichAux<<codigo<<endl;
		}


	}
		fichPacientes.close();
		fichAux.close();
		remove("Pacientes.txt");
		rename("auxiliar.txt","Pacientes.txt");


}


void Programa::modificarSeguridad(string DNI){
	string seguridadaux,ape,tele,seguridad,codigo,linea,nom;
	fstream fichPacientes;
	fichPacientes.open("Pacientes.txt",ios::in);
	fstream fichAux;
	fichAux.open("auxiliar.txt",ios::out);

	while(getline(fichPacientes,linea)){
		if(linea.find(DNI)!=string::npos){
			cout<<"Introduzca el nuevo seguro:"<<endl;
			cin>>seguridadaux;
			fichAux<<"DNI:"<<DNI<<endl;
			getline(fichPacientes,nom);
			fichAux<<nom<<endl;
				getline(fichPacientes,ape);
				fichAux<<ape<<endl;
				getline(fichPacientes,tele);
				fichAux<<tele<<endl;
				getline(fichPacientes,seguridad);
				fichAux<<"Seguridad:"<<seguridadaux<<endl;
				getline(fichPacientes,codigo);
				fichAux<<codigo<<endl;

		}
		else{
			fichAux<<linea<<endl;
			getline(fichPacientes,nom);
			fichAux<<nom<<endl;
			getline(fichPacientes,ape);
			fichAux<<ape<<endl;
			getline(fichPacientes,tele);
			fichAux<<tele<<endl;
			getline(fichPacientes,seguridad);
			fichAux<<seguridad<<endl;
			getline(fichPacientes,codigo);
			fichAux<<codigo<<endl;
		}


	}
		fichPacientes.close();
		fichAux.close();
		remove("Pacientes.txt");
		rename("auxiliar.txt","Pacientes.txt");
}


void Programa::modificarCodigo(string DNI){
	string codigoaux,ape,tele,seguridad,codigo,linea,nom;
	fstream fichPacientes;
	fichPacientes.open("Pacientes.txt",ios::in);
	fstream fichAux;
	fichAux.open("auxiliar.txt",ios::out);

	while(getline(fichPacientes,linea)){
		if(linea.find(DNI)!=string::npos){
			cout<<"Introduzca el nuevo codigo:"<<endl;
			cin>>codigoaux;
			fichAux<<"DNI:"<<DNI<<endl;
			getline(fichPacientes,nom);
			fichAux<<nom<<endl;
				getline(fichPacientes,ape);
				fichAux<<ape<<endl;
				getline(fichPacientes,tele);
				fichAux<<tele<<endl;
				getline(fichPacientes,seguridad);
				fichAux<<seguridad<<endl;
				getline(fichPacientes,codigo);
				fichAux<<"Codigo:"<<codigoaux<<endl;

		}
		else{
			fichAux<<linea<<endl;
			getline(fichPacientes,nom);
			fichAux<<nom<<endl;
			getline(fichPacientes,ape);
			fichAux<<ape<<endl;
			getline(fichPacientes,tele);
			fichAux<<tele<<endl;
			getline(fichPacientes,seguridad);
			fichAux<<seguridad<<endl;
			getline(fichPacientes,codigo);
			fichAux<<codigo<<endl;
		}


	}
		fichPacientes.close();
		fichAux.close();
		remove("Pacientes.txt");
		rename("auxiliar.txt","Pacientes.txt");
}


void Programa::menuModificar(string DNI){
	int opcion;
	do{
		cout<<"_________MODIFICAR PACIENTE__________\n"<<endl;
		cout<<"1 para modificar el nombre"<<endl;
		cout<<"2 para modificar los apellidos"<<endl;
		cout<<"3 para modificar el telefono"<<endl;
		cout<<"4 para modificar la seguridad"<<endl;
		cout<<"5 para modificar el codigo postal"<<endl;
		cout<<"6 para volver al menu principal\n"<<endl;

		cin>>opcion;

		switch(opcion){
			case 1: system("clear");
					modificarNombre(DNI);
		break;
			case 2: system("clear");
					modificarApellidos(DNI);
		break;
			case 3: system("clear");
					modificarTelefono(DNI);
		break;
			case 4: system("clear");
					modificarSeguridad(DNI);
		break;
			case 5: system("clear");
					modificarCodigo(DNI);
		break;
		}

	}while(opcion>=1 && opcion<=5);

}

void Programa::mostrarPacientes(){
	fstream fichPacientes;
	fichPacientes.open("Pacientes.txt",ios::in);
	string linea,linea2,linea3,linea4,linea5,linea6;

	while(getline(fichPacientes,linea)){
		cout<<linea+"\n";
		getline(fichPacientes,linea2);
		cout<<linea2+"\n";
		getline(fichPacientes,linea3);
		cout<<linea3+"\n";
		getline(fichPacientes,linea4);
		cout<<linea4+"\n";
		getline(fichPacientes,linea5);
		cout<<linea5+"\n";
		getline(fichPacientes,linea6);
		cout<<linea6+"\n";
		cout<<"\n";
	}

	fichPacientes.close();
}

void Programa::anadirHistoria(string DNI){
	string buscaDNI="DNI:"+DNI;
    char sintoma[250];
    char tratamiento[250];
    char regularidad[250];
    int dec;																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																											
	
	string linea,linea2,linea3,linea4,linea5,linea6;

   string nomfich=DNI+".txt";
	ifstream fichHistoria(nomfich.c_str());

	if(!fichHistoria){
		
		ofstream fichHistoria(nomfich.c_str());
	

	//if(existe(DNI)==false){
			
	
	fichHistoria.open(DNI+".txt",ios::out);
	fichHistoria.close();
	fichHistoria.open(DNI+".txt",ios::app);

		ifstream fichPacientes;
	fichPacientes.open("Pacientes.txt",ios::in);

	if(!fichPacientes.is_open()){
		fichPacientes.open("Pacientes.txt",ios::in);
	}

	while(getline(fichPacientes,linea)){
		if(linea==buscaDNI){
			getline(fichPacientes,linea2);
			getline(fichPacientes,linea3);
			getline(fichPacientes,linea4);
			getline(fichPacientes,linea5);
			getline(fichPacientes,linea6);
			

		}

		}  
            fichHistoria<<"\t\t\t\tHISTORIA CLINICA\n";
            fichHistoria<<"-----------------------------------------------"<<endl;

			fichHistoria<<linea2+"\n";
			fichHistoria<<linea3+"\n";
			fichHistoria<<linea4+"\n";
			fichHistoria<<linea5+"\n";
			fichHistoria<<linea6+"\n";

			cout<<"\n\n\nIntroduce los sintomas que presenta el paciente:"<<endl;
          getchar();
          cin.getline(sintoma,250,'\n');
          fichHistoria<<"-----------------------------------------------"<<endl;
          fichHistoria<<"SINTOMAS\n";
	       fichHistoria<<sintoma;

          cout<<"Introduzca:\n [0] si desea añadir un tratamiento\n [1] si no desea añadir un tratamiento"<<endl;
          //getchar();
          cin>>dec;

          if(dec==0){
          	fichHistoria<<"\nTRATAMIENTO\n";
          cout<<"\nIntroduce el tratamiento que presenta el paciente:"<<endl;
          getchar();
           cin.getline(tratamiento,250,'\n');

			fichHistoria<<tratamiento;

          cout<<"\nIntroduce la regularidad del tratamiento que presenta el paciente:"<<endl;
           fichHistoria<<"\nREGULARIDAD\n";
           cin.getline(regularidad,250,'\n');

			fichHistoria<<regularidad;
			cout<<"Historia añadida con exito"<<endl;

                    }

          if(dec!=0){
         cout<<"Historia añadida con exito"<<endl;
     }


	
	fichHistoria.close();
	fichPacientes.close();
			
}
           
           //if(existe(DNI)==true){
            else{
           	
           	fstream fichHistoria;
           	fichHistoria.open(DNI+".txt",ios::app);


          cout<<"\n\n\nIntroduce los sintomas que presenta el paciente:"<<endl;
          getchar();
          cin.getline(sintoma,250,'\n');
          fichHistoria<<"-----------------------------------------------"<<endl;
          fichHistoria<<"SINTOMAS\n";
	       fichHistoria<<sintoma;

          cout<<"Introduzca:\n [0] si desea añadir un tratamiento\n [1] si no desea añadir un tratamiento"<<endl;
           //getchar();
          cin>>dec;

          if(dec==0){
          	fichHistoria<<"\nTRATAMIENTO\n";
          cout<<"\nIntroduce el tratamiento que presenta el paciente:"<<endl;
          getchar();
           cin.getline(tratamiento,250,'\n');

			fichHistoria<<tratamiento;

          cout<<"\nIntroduce la regularidad del tratamiento que presenta el paciente:"<<endl;
           fichHistoria<<"\nREGULARIDAD\n";
           cin.getline(regularidad,250,'\n');

			fichHistoria<<regularidad;
			fichHistoria<<"\n";
			fichHistoria<<"-----------------------------------------------"<<endl;
			cout<<"Historia añadida con exito"<<endl;
                    }

         if(dec!=0){
         cout<<"Historia añadida con exito"<<endl;
          }
           
	
	fichHistoria.close();
}

}

  void Programa::mostrarHistoria(string DNI){
      string cadena;
    fstream fichHistoria;
	fichHistoria.open(DNI+".txt",ios::in);
     if(fichHistoria.is_open()){
            while(!fichHistoria.eof()){
      	    	getline(fichHistoria,cadena);

      		cout<<cadena<<endl;
            }
 		}

 		else{cout<<"Error al abrir la Historia clinica"<<endl;}

      fichHistoria.close();	

  
}

/*bool Programa::existe(string DNI){

	fstream f;
	string texto;
	f.open(DNI+".txt", ios::in);
	getline(f,texto);

		if (!f.eof()){
		f.close();
		return false;
		}
		else{
			f.close();
			return true;
		}
}*/