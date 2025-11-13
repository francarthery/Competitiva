#include <cmath>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, i, j, s;
	
	bool b;
	
	while(cin >> n){
		b = false;
		//i va a ser el número menor de la suma de dos cuadrados
		i = 0;
		//j va a ser el número mayor de la suma de dos cuadrados
		j = sqrt(n);
		
		while(j >= i){
			//s= la suma de los dos posibles enteros
			s = pow(i,2) + pow(j,2);
	
			if(s == n){
				b = true;
				break;
			
			// Se suben o bajan los 2 enteros tratando de encontrar que su suma de el N introducido
			}else if(s < n){
				i++;
			}else{
				j--;
			}
		}
		if(b==true) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}

//Solo va a ser posible la suma si i es el menor de ambos números
