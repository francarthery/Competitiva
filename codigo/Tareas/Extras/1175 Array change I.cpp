#include <iostream>

using namespace std;

int main() {
	
	int N;
    //,ULT_20=19, aux_i=0, aux_ult=0;
	int LISTA[20];
	
    //Se leen los valores
	for(int i=0; i<=19; i++){
		cin >> N;
		LISTA[i]=N;}
	
    //Se cambian el ultimo por el primer valor y así sucesivamente(Hecho con variable auxiliar)
	for(int i=0, j=19; i<=9; i++, j--){
        swap(LISTA[i], LISTA[j]);
    }
    
    //Se reproducen los valores
    for(int i=0; i<=19; i++){
        cout << "N[" << i << "] = " << LISTA[i] << endl;
    }
	
	return 0;
}