#include <iostream>
#include <cmath>
using namespace std;

int inversor(int i, int dig);
int cant_digitos(int i);

int main(int argc, char *argv[]) {
	
	int i, j, dig;
	
	cin >> i;
	
	dig = cant_digitos(i);
	
	j = inversor(i, dig);
	
	cout << i << " " << j << endl;
	
	if (i == j)
		cout << "es palindromo" << endl;
	else
		cout << "no es palindromo" << endl;
	
	return 0;
}

int inversor(int N, int dig){
	
	if (N < 10) return N;
	else return (N % 10) * pow(10, dig-1) + inversor(N / 10, dig - 1);
}
	
int cant_digitos(int N){
	if (N < 10) return 1;
	else return 1 + cant_digitos(N / 10);
}
	

