#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

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

int main() {
	
	int legajo, legajo_aux;
	char contra[6], sex_aux, rol_aux, nom[20], ape[20];
	
	ifstream nombre, apellido, sexo, rol;
	ofstream archivo_bin;
	
	nombre.open("nombres.txt");
	apellido.open("apellidos.txt");
	sexo.open("sexo.txt");
	rol.open("rol.txt");
	//Es NECESARIO aclarar que es binario. Sino no anda correctamente
	archivo_bin.open("usuarios.bin", ios::binary);
	
	ofstream pepe;
	
	pepe.open("credenciales_usuarios.txt");
	
	for(int i = 0; i < 100; i++){
		
		Info auxiliar;
		char aux[6];
		
		legajo = (rand() % 80000) + 10000;
		legajo_aux = legajo;
		
		//Pasamos a cadena de caracteres el legajo
		for(int i = 4; i >= 0; i--){
			aux[i] = char((legajo_aux % 10) + '0');
			legajo_aux /= 10;
		}
		aux[5] = '\0';
		
		contra[0] = aux[4]; contra[1] = aux[3]; contra[2] = aux[2]; contra[3] = aux[1]; contra[4] = char(((int(aux[0])-'0') + (int(aux[4])-'0'))%10 + '0');

		nombre.getline(nom, 20);
		apellido.getline(ape, 20);
		sexo >> sex_aux;
		rol >> rol_aux;
		
		auxiliar.id = i;
		strcpy(auxiliar.nombre, nom);
		strcpy(auxiliar.apellido, ape);
		auxiliar.sexo = sex_aux;
		strcpy(auxiliar.legajo, aux);
		strcpy(auxiliar.password, contra);
		auxiliar.rol = rol_aux;
		auxiliar.ult_acceso.dia = rand() % 30 + 1;
		auxiliar.ult_acceso.mes = rand() % 12 + 1;
		auxiliar.ult_acceso.anio = rand() % 11 + 2013;
		
		archivo_bin.write((char *)(&auxiliar), sizeof(Info));
	
		pepe << setfill(' ');
		pepe << setw(3) << auxiliar.id << setw(18) << auxiliar.nombre << setw(14) << auxiliar.apellido << "    " << auxiliar.sexo << "   ";
		pepe << auxiliar.legajo << "   " << auxiliar.password << "    " << auxiliar.rol << "   ";
		pepe << setw(3) << auxiliar.ult_acceso.dia << setw(6) << auxiliar.ult_acceso.mes << "    " << auxiliar.ult_acceso.anio;
		pepe << endl;
		
		
		
		cout << setfill(' ');
		cout << setw(3) << auxiliar.id << setw(18) << auxiliar.nombre << setw(14) << auxiliar.apellido << "    " << auxiliar.sexo << "   ";
		cout << auxiliar.legajo << "   " << auxiliar.password << "   " << auxiliar.rol << "   ";
		cout << setw(4) << auxiliar.ult_acceso.dia << setw(6) << auxiliar.ult_acceso.mes << "    " << auxiliar.ult_acceso.anio;
		cout << endl;
		
	}	
	
	// Cerrar archivos
	nombre.close();
	pepe.close();
	apellido.close();
	sexo.close();
	rol.close();
	archivo_bin.close();
		
	return 0;
}

