#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	 
	float N, I=0, SUMA=0;
	
	while(I<2){
		cin >> N;
		if(N>=0 and N<=10){
			SUMA+=N;
			I++;}
		else
			cout << "nota invalida" << endl;}
	
	cout << "media = " << SUMA/2 << endl;

	return 0;
}

