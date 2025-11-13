#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	// Declaracion de variables
	int A,B,C,D;
	
	// Leemos datos de entrada	
	// comentario de multiples ....
	cin >> A >> B >> C >> D;
	
	// proceso y mostrar datos de salida	
	if ( B>C and D>A and (C+D)>(A+B) and C>0 and D>0 and A%2==0 )
		cout << "Valores aceitos" << endl;
	else {
		cout << "Valores nao aceitos";
	    cout << endl;
	}
	
	return 0;
	
}

/*
   8/2 = 4 ,  resto 0
   7/2 = 3 ,  resto 1
   5/2 ...,   resto 1
*/

