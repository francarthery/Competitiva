#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
	
	int M,N,MENOR,MAYOR,suma;
	
	cin >> M >> N;
	
	while(M>0 and N>0){
		if(M>N){
			MENOR=N;
			MAYOR=M;}
		else{
			MENOR=M;
			MAYOR=N;}
		suma=0;
		for(int i=MENOR; i<=MAYOR; i++){
			suma=suma+i;
			printf("%d ", i);}
		cout << "Sum=" << suma << endl;
		cin >> M >> N;
	}
	return 0;
}


