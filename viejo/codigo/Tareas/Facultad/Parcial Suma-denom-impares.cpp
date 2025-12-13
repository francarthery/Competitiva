#include <iostream>
#include <iomanip>

using namespace std;

bool SinDigitosX(int N, int D);
double Sumatoria(int T, int D);


int main(){
	
	int T, D;
	
	cin >> T >> D;
	
	cout << fixed << setprecision(5);
	cout << "S=" << Sumatoria(T, D) << endl;
	
	return 0;
}
	
bool SinDigitosX(int N, int D){
	
	if (N <= 0) return 0;
	else{
		if(N % 10 == D) return 1;
		else return SinDigitosX(N / 10, D);
	}
}

double Sumatoria(int T, int D){
	
	double rta = 1;
	int contador = 1;
	int N = 3;
	
	while(contador < T){
		if(!SinDigitosX(N, D)){
			rta += 1.0 / N;
			contador++;
		}
		
		N += 2;
	}
	
	return rta;
}
