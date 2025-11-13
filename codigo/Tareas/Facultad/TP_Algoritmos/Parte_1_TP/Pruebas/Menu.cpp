#include <iostream>
#include <iomanip>

using namespace std;


int main(){

void menu_principal(){
	char opcion, confirmacion;
	bool c= false;

	cout << setw(20) << "Menú Principal" << endl;
	cout << setfill('=') << setw(26) << "=" << endl;
	
	cout << "1.- Abecedarios" << endl;
	cout << "2.- Juegos" << endl;
	cout << "X.- Salir de la aplicación" << endl;
	
	cout << "Ingrese una opción: ";
	cin >> opcion;
	
	switch(opcion){
	case '1':
		//menu_abecedarios();
		break;
		
	case '2':
		//menu_juegos();
		break;
		
	case 'X':	
		cout << "Est seguro que desea salir de la aplicación? [S/N]" << endl;
		do{
			cin >> confirmacion;

			if(confirmacion == 'S'){
				//puede ir alguna otra cosa
				cout << "Gracias por su visita. Hasta pronto!" << endl;
				c = true;

			}else if(confirmacion == 'N'){
				menu_principal();
				c = true;

			}else {
				cout << "Caracter incorrecto. Ingrese confirmación nuevamente: ";
			}
		}while(!c);
		break;
		
	default:
		cout << "La opción ingresada no es correcta"<< endl;
		    menu_principal();
		break;
		
	}
	return 0;
}
}