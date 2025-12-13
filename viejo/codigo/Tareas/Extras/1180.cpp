#include <iostream>
#include <array>

using namespace std;

int main() {
	
	int N, C, MENOR, POSICION=0;

    cin >> C;
    int X[C];

    for(int i=0; i<C; i++){
        cin >> N;
        X[i]=N;}

	MENOR=N;

    for(int i=0; i<C; i++){
       if(X[i]<=MENOR){
           MENOR=X[i];
           POSICION=i;
       }}
       
    cout << "Menor valor: " << MENOR << endl;
    cout << "Posicao: " << POSICION << endl;
       
	return 0;
}