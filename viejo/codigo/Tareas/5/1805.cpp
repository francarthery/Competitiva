#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	long long int A,B,suma;
	
	cin >> A >> B;
	suma=0;
	suma = (A + B) * (B-A+1)/2;
	
	cout << suma << endl;
	
	return 0;
}

