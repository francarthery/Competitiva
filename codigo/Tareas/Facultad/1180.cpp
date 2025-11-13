#include <iostream>

using namespace std;

int main() {
	
	int C, MENOR, POSICION=0;

    cin >> C;
    int X[C];

    for(int i = 0; i < C; i++){
        cin >> X[i];
    }

	MENOR = X[0];

    for(int i=0; i<C; i++){
       if(X[i]<=MENOR){
           MENOR=X[i];
           POSICION=i;
       }
    }
       
    cout << "Menor valor: " << MENOR << endl;
    cout << "Posicao: " << POSICION << endl;
       
	return 0;
}