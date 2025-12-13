#include <iostream>

using namespace std;

int main() {
	
	int N, B, b, contador, max_cont;
	
	for(;;){
		cin >> N >> B;
		
		if (N < 0 or B < 2 ) break;
		
		contador = 0;
		max_cont = N;
		int lista[B];
		int cont[N + 1];
		
        //Lista bolas 
		for(int i = 0; i < B; i++){
			cin >> b;
			lista[i] = b;
		}
		//Se escribe contador que contiene numeros que se deben obtener
		for (int i = 0; i <= N; i++)
			cont[i] = i;
		
		//Se recorren todas las posibilidades de resta y se comparan con los valores de "cont"
		for(int i = 0; i < B; i++){

			for(int j = 0; j < B; j++){

				/*Si un valor ya se encontro se quita de la lista "cont", "Max_cont" va a 
				disminuir consecuentemente para que se tome un valor - de la cont*/
				for(int c = 0; c<=max_cont; c++){

					if(lista[i] - lista[j] == cont[c]) {
						contador++;
						
						for(int b = c; b <= max_cont; b++){
							//Borrado elemento encontrado lista
							cont[b] = cont[b + 1];		
					}
						max_cont--;
					}}}}

	if (contador == N + 1) cout << "Y" << endl;
	else cout << "N" << endl;
	}
	
	return 0;
}


/* N va a determinar hasta que numero van a llegar las bolas. N+1 la cantidad inicial.
B determina cuantas bolas hay en la bolsa
b determina que bolas permanecieron en la bolsa*/