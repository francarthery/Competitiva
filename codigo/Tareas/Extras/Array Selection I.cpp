#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main() {
	
	float N, contador=0;
	float LISTA[100];
	
	for(int i=0; i<=99; i++){
		cin >> N;
		LISTA[i]=N;}
	
	for(int i=0; i<=99; i++){
        if(LISTA[i]<=10)
		    cout << "A[" << i << "] = " << fixed << setprecision(1) << LISTA[i] << endl;}
	
	return 0;
}