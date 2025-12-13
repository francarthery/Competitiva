#include <iostream>
#include <cstring>
 
using namespace std;
 
int main() {
 
    int N, LONG, P1, P2, P3, P4, P5;
    string R;

    //Pedimos el texto en forma de String
    cin >> N;
    cin.ignore();
	getline(cin, R);

    LONG=R.length();

    //Declaramos un array que es donde vamos a guardar el string
    char TEXT[LONG+1];
    strcpy(TEXT, R.c_str());

    //Recorremos array y corregimos las palabras que estén mal
    for(int i = 0; i < LONG; i++){
        
        //Se almacenan el caracter que se esta leyendo y los 4 anteriores
        P5=P4;
        P4=P3;
        P3=P2;
        P2=P1;
        P1=TEXT[i];

        /*Se corrige el texto. Hay que tener en cuenta que si las palabras tienen antes
        o después otra letra NO deben ser corregidas, por ejemplo OBES o EURO. Solo si
        tienen un espacio al principio y final o si el programa comienza o termina en esa
        palabra deben ser corregidas. Eso es lo que se contempla en el siguiente condicional.
        */
        
        //Casos palabra NO tiene letras extra, solo 3:
        if(P5==' ' and P4=='O' and P3=='B' and P2!='I' and P1==' ')
            TEXT[i-1]='I';
        else if(P5==' ' and P4=='U' and P3=='R' and P2!='I' and P1==' ')
            TEXT[i-1]='I';
        //Casos programa termina en palabra a corregir
        else if(P4==' ' and P3=='U' and P2=='R' and P1!='I' and i==LONG-1)
            TEXT[i]='I';
        else if(P4==' ' and P3=='O' and P2=='B' and P1!='I' and i==LONG-1)
            TEXT[i]='I';
        //Casos programa empieza en palabra a corregir
        else if(P3=='O' and P2=='B' and P1!='I' and i==2)
            TEXT[i]='I';
        else if(P3=='U' and P2=='R' and P1!='I' and i==2)
            TEXT[i]='I';
    }

    //Se imprime array corregido
    for(int i = 0; i < LONG; i++)
        cout << TEXT[i];

    return 0;
}