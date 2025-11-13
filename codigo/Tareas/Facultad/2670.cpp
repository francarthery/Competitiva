#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int A1, A2, A3, T1, T2, T3;
	
	cin >> A1 >> A2 >> A3;
	
	//Si esta en el piso 1
	T1 = A2 * 2 + A3 * 4;
	//Si esta en el piso 2
	T2 = A1 * 2 + A3 * 2;
	//Si esta en el piso 3
	T3 = A1 * 4 + A2 * 2;
	
	if(T1 < T2 and T1 < T3)
		cout << T1 << endl;
	else if(T2 < T3)
		cout << T2 << endl;
	else 
		cout << T3 << endl;
	return 0;
}

