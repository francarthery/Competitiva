#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	
	float suma;
	int N;
	int contador=0;
	
	cin >> N;
	suma=0;
	while(N>0){
		suma=suma+N;
		contador++;
		cin >> N;
	}
	cout << fixed << setprecision(2);
	cout << suma/contador << endl;
	return 0;
}

