#include <iostream>
#include <algorithm>

using namespace std;

bool busqueda(long long int arr[], int N, int buscar);

int main(){

    long long int posible1, posible2, rta = 0;
    int N;
    long double posible3;
    long long int numeros[500];

    cin >> N;

    while(N != -1){
        int suma = 0;
        rta = 0;
        for(int i = 0; i < N - 1; i++){
            cin >> numeros[i];
            suma += numeros[i];
        }

        sort(numeros, numeros + (N - 1));

        posible1 = numeros[(N - 1) / 2 - 1] * N - suma;
        posible2 = numeros[((N - 1) / 2)] * N - suma;
        posible3 = (float)suma / (N - 1);

        if(!busqueda(numeros, N, posible1) and posible1 < numeros[((N - 1) / 2) - 1])
            rta++;
        if(!busqueda(numeros, N, posible2) and posible2 > numeros[((N - 1) / 2)])
            rta++;
        if(!busqueda(numeros, N, posible3 ) and (posible3 - (int)posible3) == 0 and posible3 > numeros[((N - 1) / 2) - 1] and posible3 < numeros[((N - 1) / 2)])
            rta++;

        cout << rta << endl;
        cin >> N;
    }
    return 0;
}

bool busqueda(long long int arr[], int N, int buscar){
	
	int inicio = 0, fin = N - 1;
	int centro = (inicio + fin) / 2;
    bool rta = true;
	
	while(arr[centro] != buscar and inicio <= fin){
		if(arr[centro] > buscar)
			fin = centro - 1;
		else
			inicio = centro + 1;
		
		centro = (inicio + fin) / 2;
	}
	if(inicio > fin)
		rta = false;
	
	return rta;
}

/*
54 -5 84 55    
3

5
-2 -95 11 34  
*/