#include <iostream>
#include <algorithm>

using namespace std;

#define TAM 100000

int cant_tablas(int tablas[], int necesarias, int K, int pista);

int main() {
	
	int N, M, L, K, R1, R2;
	int tablas[TAM];
	
	cin >> N >> M;
	
	while(N != 0 or M != 0){
		cin >> L >> K;
		R1 = 0, R2 = 0;
		
		for(int i = 0; i < K; i++){
			
			cin >> tablas[i];
		}
		
		sort(tablas, tablas + K);
		
		if((M * 100) % L == 0)
			R1 = cant_tablas(tablas, (M*100)/L, K, N);
		
		if((N * 100) % L == 0)
			R2 = cant_tablas(tablas, (N*100)/L, K, M);
		
		
		if(R1 == 0 and R2 == 0)
			cout << "Impossivel" << endl;
		else if((R1 != 0 and R2 != 0 and R1 < R2) or (R2 == 0 and R1 != 0))
			cout << R1 << endl;
		else
			cout << R2 << endl;
		
		cin >> N >> M;
	}
	
	return 0;
}

int cant_tablas(int tablas[], int necesarias, int K, int pista){
	
	int tengo = 0, bajo = 0, rta = 0;
	K--;
	
	while(tablas[K] >= pista and necesarias > tengo){
		
		if(tablas[K] == pista){
			tengo++;
			rta++;
		}
		K--;
	}
	
	while(bajo < K and necesarias > tengo){
		if(tablas[K] + tablas[bajo] == pista){
			bajo++;
			K--;
			tengo++;
			rta += 2;
		}
		else if(tablas[K] + tablas[bajo] > pista)
		   K--;
		else
			bajo++;
	}
	
	if(tengo < necesarias)
		  rta = 0;
	
	return rta;
	
}
	

/*
1-) Recibimos largos de tablas.

2-) Nos fijamos que el ancho de las tablas sea un divisor del largo o del ancho de la pista.

3-) Ordenamos el array. 

4-) Buscamos con busqueda binaria si hay una tabla de la longitud exacta de la pista.
Aca tenemos dos posibilidades:
    --Si la encontramos miramos hacia adelante hasta que el valor sea mayor y nos quedamos con la posición anterior.

    -- Si no esta, la función nos va a devolver el valor consecutivo menor en la lista.

5-) Nos fijamos cuantas hay del tamaño exacto de la pista, la cantidad la sumamos
a un contador de filas que necesitamos y por cada tabla encontrada reducimos el tamaño lógico.

6-) Vamos comparando el primer valor con el último. 
    --Si su suma = al tamaño de la pista hacemos TL-1, inicio+1

    --Si la suma da mas que el tamaño de la pista hacemos inicio+1
    
    --Si la suma da menor que el tamaño de la pista hacemos TL-1





Si el largo L es un número impar, la suma de tablas va a tener que ser un par+impar

Si el largo L es un número par, la suma

*/