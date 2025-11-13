#include <iostream>
#include <iomanip>

float PV(char L);
int Vocal(char L);

using namespace std;

int main(){
	
	char L;
	
	cin >> L;
	
	cout << fixed << setprecision(4);
	cout << "PV=" << PV(L) << endl;
	
	return 0;
}
	
int Vocal(char L){
	
	if(L == 'a') return 1;
	else if(L == 'e') return 2;
	else if(L == 'i') return 3;
	else if(L == 'o') return 4;
	else if(L == 'u') return 5;
	else return Vocal(--L);
}
	
float PV(char L){
	float rta = 1;
	char letra = 'a';
	
	while(letra <= L){
		rta *= (1 + float(1.0 / Vocal(letra)));
		++letra;
	}
	return rta;
}
