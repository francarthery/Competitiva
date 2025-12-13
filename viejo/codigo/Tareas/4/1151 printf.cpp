#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N,X,anterior_1,anterior_2;
	
	cin >> N;
	
	anterior_1=1;
	anterior_2=0;
	X=0;
	printf("0 1 ");

	for(int i=2; i<N; i++){
		X=anterior_1+anterior_2;
		printf("%d", X);
		if((i+1)<N)
			printf(" ");
		anterior_2=anterior_1;
		anterior_1=X;
	}
	return 0;
}

/*Se tiene que empezar con 0 y 1 y luego empezar a sumar */
