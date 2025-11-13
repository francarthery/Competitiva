#include <iostream>
#include <iomanip>

using namespace std;


int main(){
// void menu_principal(){
    char opcion, confirmacion;

    cout << setw(20) << "Menu Principal" << endl;
    cout << setfill('=') << setw(30) << endl;

    cout << "1.- Abecedarios" << endl;
    cout << "2.- Juegos" << endl;
    cout << "X.- Salir de la aplicaci" << char(162) << "n" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch(opcion){
        case '1':
            //menu_abecedarios();
            break;

        case '2':
           // menu_juegos();
            break;

        case 'X':	
            cout << "Esta seguro que desea salir de la aplicacion? [S/N]" << endl;
            cin >> confirmacion;
        
            if(confirmacion == 'S'){
                //puede ir alguna otra cosa
                cout << "Gracias por su visita. Hasta pronto!" << endl;
            }else if(confirmacion == 'N'){
                //menu_principal();
            }
            break;
        
        default:
        cout << "La opcion ingresada no es correcta"<< endl;
        //menu_principal();
            break;
    
    }
    return 0;
}