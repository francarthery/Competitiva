#include <iostream>
using namespace std;

struct Usuario{
	string nombre;
	string password;
	struct Fecha{
		int dia;
		int mes;
		int anio;
	}nacimiento;
	unsigned notas[5];
};

void pedir_datos(Usuario user1);

int main(int argc, char *argv[]) {
	
	Usuario user1 = {"francisco", "carthery", {31,10,2004}, {6, 7, 8, 9, 0}};
	
	pedir_datos(user1);
	
	cout << endl << endl << "Sus datos son: " << endl;
	cout << "Nombre: " << user1.nombre << endl;
	cout << "Password: " << user1.password << endl;
	cout << "Nacimiento: " << user1.nacimiento.dia << "/" << user1.nacimiento.mes << "/" << user1.nacimiento.anio << endl;
	cout << "Sus notas fueron: ";
	for(int i = 0; i < 5; i++){
		cout << user1.notas[i] << "  ";
	}
	
	
	return 0;
}

void pedir_datos(Usuario user1){
	
	cout << "ingrese su nombre: ";
	getline(cin, user1.nombre);
	
	cout << endl << "ingrese su contasenia: ";
	getline(cin, user1.password);
	
	cout << endl << "Ingrese su fecha de nacimiento. Formato: dia mes anio";
	cin >> user1.nacimiento.dia >> user1.nacimiento.mes >> user1.nacimiento.anio;
	
	cout << endl << "Ingrese sus notas: ";
	for(int i = 0; i < 5; i++){
		cin >> user1.notas[i];
	}
}

