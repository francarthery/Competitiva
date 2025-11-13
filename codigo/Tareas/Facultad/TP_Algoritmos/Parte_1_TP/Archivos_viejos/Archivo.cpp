#include <iostream>
#include <math.h>
#include <string>

#define TAM 6

using namespace std;

void bienvenida();
bool login();
bool verificacion_user(int);
bool verificacion_password(int, char []);
int inversoR (int, int);


int main(){
    
    if (login()) 
        bienvenida();

    return 0;
}

void bienvenida() {
    
    cout << "Bienvenido" << endl;

}

//------------------------------------------------- Login ------------------------------------------------------------

bool login() {
    int contador = 1, usuario;
    char password[TAM];
    
    bool valido = false;

    cout << "Ingrese su ID de usuario: " << endl;
    cin >> usuario;
    
    cout << "Ingrese su contrasena: " << endl;
    cin.ignore();
    gets(password);
    
    while(!valido and contador < 3){
        
        if(verificacion_user(usuario) and verificacion_password(usuario, password))
            valido = true;
        else{
            cout << "Usuario o contrasena incorrecta. Intente nuevamente" << endl;
            contador++;

            cout << "Usuario: " << endl;
            cin >> usuario;
            cin.ignore();
            
            cout << "Contrasena: " << endl;
            gets(password);
        }
        
    }
    
    if (contador == 3) 
        cout << "Demasiados intentos incorrectos. Pruebe de nuevo más tarde" << endl;
    
    return valido;
    
}

bool verificacion_user (int usuario) {
    bool rta = false;

    if(usuario >= 10000 and usuario < 90000)
        rta = true;

    return rta;
}

bool verificacion_password (int usuario, char contrasena[]) {
    bool rta = true;
    int contra_correcta;
    int primer_num = usuario / 10000;
    int ultimo_num = usuario % 10;

    contra_correcta = inversoR(usuario, 0) - primer_num + (primer_num + ultimo_num) % 10;
   
    for(int i = 4; i >= 0; i--){
        if(contrasena[i] - '0' != (contra_correcta % 10))
            rta = false;
        
        contra_correcta /= 10;
    }
 
    return rta;
}

int inversoR(int numero, int numero_inverso){
	int digito = numero % 10;

	if (numero == 0){
		return numero_inverso;
	}else{
		numero_inverso = numero_inverso * 10 + digito;
		return inversoR(numero / 10, numero_inverso);
	}
}

//------------------------------------------------- Bienvenida ------------------------------------------------------------
