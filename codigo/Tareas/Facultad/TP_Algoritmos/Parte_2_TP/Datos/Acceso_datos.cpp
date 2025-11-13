#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Fecha{
	int dia;
	int mes;
	int anio;
};

struct Info{
	int id;
	char nombre[20];
	char apellido[20];
	char sexo;
	char legajo[6];
	char password[6];
	char rol;
	Fecha ult_acceso;
};

bool busqueda_usuario(Info &auxiliar, char legajo_ingreso[], char contra_ingreso[]);

int main() {
	
	Info datos;
	char legajo[] = "22316";
	char contra[] = "61328";
	
	if(busqueda_usuario(datos, legajo, contra))
		cout << datos.nombre << " " << datos.apellido << endl;
	else
		cout << "Usuario incorrecto" << endl;
	
	
	return 0;
}

bool busqueda_usuario(Info &auxiliar, char legajo_ingreso[], char contra_ingreso[]){
	
	int i = 0;
	bool flag = true;
	ifstream datos;
	
	datos.open("usuarios.bin", ios::binary);
	
	if(!datos)
		cout << "Error al abrir el fichero" << endl;
	else{
		
		while(i < 100 and flag){
			
			if(!datos.eof()){
				//Leemos cada uno de los usuarios buscando el legajo ingresado por el usuario
				datos.read((char*)(&auxiliar), sizeof(auxiliar));
				
				if(!strncmp(auxiliar.legajo, legajo_ingreso,5) and !strncmp(auxiliar.password, contra_ingreso, 5))
					flag = false;
				else
					i++;
			}
		}
	}
	
	return !flag;
}

