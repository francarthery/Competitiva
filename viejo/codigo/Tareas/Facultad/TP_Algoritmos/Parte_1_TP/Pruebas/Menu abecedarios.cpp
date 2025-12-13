#include <iostream>
#include <string> 
#include <iomanip>

using namespace std;

void espanol();
void ingles();
void italiano();
void portugues();
void frances();
void letras_minusculas();
void letras_mayusculas();
void acento_agudo();
void acento_grave();
void letras_circunflejo();


int main(){
char opcion, confirmacion;
bool c= false;

cout << setw(20) << "Menu Abecedario" << endl;
cout << setfill('=') << setw(25) << "=" << endl;

    cout << "1.- Espanol" << endl;
    cout << "2.- Ingles" << endl;
    cout << "3.- Italiano" << endl;
    cout << "4.- Portugues" << endl;
    cout << "5.- Frances" << endl;
    cout << "X.- Volver al menu principal" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch(opcion){
        case '1':
            espanol();
            break;

        case '2':
            ingles();
            break;

        case '3':
            italiano();
            break;

        case '4':
            portugues();
            break;

        case '5':
            frances();
            break;

        case 'X':	
            cout << "Esta seguro que desea volver al menu principal? [S/N]" << endl;
        do{
            cin >> confirmacion;

            if(confirmacion == 'S'){
                system("cls");
                menu_principal();
                c = true;

            }else if(confirmacion == 'N'){
                system("cls");
                menu_abecedario();
                c = true;

            }else{
                system("cls");
                cout << setw(20) << "Menu Abecedario" << endl;
                cout << setfill('=') << setw(25) << "=" << endl;

                cout << "1.- Espanol" << endl;
                cout << "2.- Ingles" << endl;
                cout << "3.- Italiano" << endl;
                cout << "4.- Portugues" << endl;
                cout << "5.- Frances" << endl;
                cout << "X.- Volver al menu principal" << endl;

                cout << "Caracter incorrecto. Ingrese confirmacion nuevamente: ";
                
            }

        }while(!c);    
            break;

        default:
        cout << "La opcion ingresada no es correcta" << endl;
        system("cls");
            menu_abecedario();
            break;
    }


    return 0;
}

void espanol(){

    cout << "Letras minusculas:" << endl;
        letras_minusculas();

    cout << endl << "Letras mayusculas:" << endl;
        letras_mayusculas();

    cout << "Letras acentuadas:" << endl;
        acento_agudo();
    
    cout << "Letra con dieresis:" << endl;
        cout << "ü" << endl;

}

void ingles(){

    cout << "Lowercase letters (letras minusculas): " << endl;
        letras_minusculas();

    cout << endl << "Capital letters (letras mayusculas):" << endl;
        letras_mayusculas();

    cout << endl << "There are no accented letters (no existen letras acentuadas)" << endl;
}

void italiano(){

    int contador=0;
	
	cout << endl;
	
	cout << "Lettere minuscole (letras minusculas): " << endl;
	
	for(char i = 'a'; i <= 'z'; i++){
		cout << i << " ";
		contador++;
		
		if(i == 'i'){
			i+=2;
		}
		if(i == 'v'){
			i+=3;
		}
		if(contador%10 == 0)
		   cout << endl;        
	}
	
	cout << endl << endl << "Lettere maiuscole (letras mayusculas):" << endl;
	
	contador=0; 
	
	for(char i = 'A'; i <= 'Z'; i++){
		cout << i << " ";
		contador++;
		
		if(i == 'I')
			i+=2;
		
		if(i == 'V')
			i+=3;

		if(contador%10 == 0)
		   cout << endl;
	}
	
cout << endl << "lettere con accento acuto (letras con acento agudo):" << endl;
    cout << "é í ó ú" << endl;

cout << endl << "Lettere gravemente accentate (letras con acento grave):" << endl;
    acento_grave();

cout << endl << "lettere circonflesse (letras con circunflejo):" << endl;
    cout << "î" << endl;

}
void portugues(){

    cout << endl << "Letras minusculas:" << endl;
        letras_minusculas();

    cout << endl << "Letras maiusculas (letras mayusculas):" << endl;
        letras_mayusculas();

    cout << endl << "Letras com acento agudo (letras con acento agudo):" << endl;
        acento_agudo();

    cout << endl << "Letras com acentos graves (letras con acento grave):" << endl;
        cout << "à" << endl;

    cout << endl << "Letras circunflexas (letras con circunflejo):" << endl;
        cout << "â ê ô" << endl;
}

void frances(){
    
    cout << endl << "Lettres minuscules (letras minusculas):" << endl;
        letras_minusculas();
    
    cout << endl << "Lettres majuscules (letras mayusculas):" << endl;
        letras_mayusculas();

    cout << endl << "Lettres avec accent  aigu (letras con acento agudo):" << endl;
        cout << "é" << endl;

    cout << endl << "Lettres avec accent grave (letras con acento grave):" << endl;
        cout << "à è ù" << endl;
    
    cout << endl << "Lettres circonflexes (letras con circunflejo):" << endl;
        letras_circunflejo();

    cout << endl << "Lettres avec tréma (letras con dieresis):" << endl;
        cout << "ë ï ü ÿ" << endl;

}

void letras_minusculas(){

    int contador=0;

    for(char i = 'a'; i <= 'z'; i++){
        cout << i << " ";
        contador++;

        if(contador%10 == 0)
        cout << endl;
    }
    cout << endl;
}

void letras_mayusculas(){

    int contador=0;

    for(char i= 'A'; i <= 'Z'; i++){
        cout << i << " ";
        contador++;

        if(contador%10 == 0)
        cout << endl;
    }
    cout << endl;
}

void letras_acentuadas(){
    cout << "á é í ó ú" << endl;
}

void acento_grave(){
    cout << "à è ì ò ù" << endl;
}

void letras_circunflejo(){
    cout << "â ê î ô û" << endl;
}