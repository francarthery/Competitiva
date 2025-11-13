#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main() {
	
	int C, N;
    long long int FIBO_1=0, FIBO_2=1, aux;
	long long int LISTA[100];
	
    cin >> C;

    //Fibonacci: 0 1 1 2 3 5 8 13 21 34 55...
	for(int i=0; i<=99; i++){
        LISTA[i]=FIBO_1;
        aux=FIBO_2;
        FIBO_2+=FIBO_1;
        FIBO_1=aux;
    }

    for (int i = 0; i < C; i++){
        cin >> N;
        cout << "Fib(" << N << ") = " << LISTA[N] << endl;
    }
	
	return 0;
}
