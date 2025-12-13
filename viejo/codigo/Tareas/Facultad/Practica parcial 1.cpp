#include <iostream>

using namespace std;

int eventosEnAumento(int []);
int sinEventosPorCOVID(int [], int);

#define TAM 52

int main(){
	
	int semanas[TAM];
	
	for(int i = 0; i < TAM; i++){
		cin >> semanas[i];
	}
	
	cout << "La mayor cantidad de semanas con crecimiento fue: " << eventosEnAumento(semanas) << endl;
	cout << "En la primera mitad de 2021 hubieron " << sinEventosPorCOVID(semanas, 26) << " semanas sin eventos por COVID" << endl;
	
	return 0;
}

int eventosEnAumento(int semanas[]){
	bool crece = false;
	int M = 0;
	int max_M = 0;
	for(int i = 0; i < TAM - 1; i++){
		if(semanas[i] < semanas[i + 1]){
			if(!crece){
				crece = true;
				M = 1;
			}
			else{
			    M++;
			    if(M > max_M)
					max_M = M;
			}
		}
		else
			crece = false;
	}
	return max_M;
}
	
int sinEventosPorCOVID(int semanas[], int contador){
	if(contador == 0) return 0;
	else if(semanas[contador] == 0) return 1 + sinEventosPorCOVID(semanas, --contador);
	else return sinEventosPorCOVID(semanas, --contador);
}
