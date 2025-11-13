#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	//Ejemplo recibimos N enteros y debemos ver si hay forma de, sumando algunos de estos
	//enteros, llegar a un numero A.
	
	int a, n;
	bool sw = 0;
	
	cin >> n >> a;
	
	vector<int> A(n);
	
	for(int i = 0; i < n; i++)
		cin >> A[i];
	
	for(int i = 0; i < (1 << n); i++){ //Iteramos todos los numeros de 0 a 2^n
		int s = 0;
		
		for(int j = 0; j < n; j++){ //Por cada numero, los bits que esten prendidos son los elementos que se usan
			if(i & (1 << j)) 
				s += A[j];
			
		}
		
		if(s == a){ //Nos fijamos si la combinacion es la buscada
			sw = 1; 
			break;
		}
	}
	
	if(sw)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	
	
	return 0;
}

