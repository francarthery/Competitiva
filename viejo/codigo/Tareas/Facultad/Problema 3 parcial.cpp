#include <iostream>
using namespace std;

#define TAM 31

int menos10Grados(int [], int);
bool  semanaDescendente(int []);

int main(int argc, char *argv[]) {
	
	int temperaturas[TAM];
	
	for(int i = 0; i < TAM; i++){
		cin >> temperaturas[i];
	}
	
	cout << "En el mes de mayo hubieron " << menos10Grados(temperaturas, TAM) << " dias con menos de 10 grados" << endl;
	if(semanaDescendente(temperaturas))
		cout << "Hubo al menos 3 dias de descenso consecutivo de temperatura" << endl;
	else
		cout << "No Hubieron más de 3 dias de descenso consecutivo de temperatura" << endl;
	
	return 0;
}

int menos10Grados(int temperaturas[], int contador){
	
	if(contador == 0) return 0;
	else{
		if(temperaturas[contador - 1] < 10) return 1 + menos10Grados(temperaturas, --contador);
		else return menos10Grados(temperaturas, --contador);
	}
}

bool semanaDescendente(int temperaturas[]){
	bool bajando = false;
	int  contador = 0;
	
	for(int i = 0; i < TAM - 1; i++){
		if(temperaturas[i] > temperaturas[i + 1]){
			if(bajando){
				contador++;
			}
			else{
				contador = 1;
				bajando = true;
			}
		}
		else
			bajando = false;
		
		if(contador == 3)
			return true;
	}
	
	return false;
}
