#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int A, B, anterior_A = -1, anterior_B = -1;
	bool iguales = false;
	
	cin >> A;
	
	int max_suma = A + B;
	
	while(A != -1){
		
		cin >> B;
		
		if(A + B > max_suma){
			max_suma = A + B;
		}
		if(anterior_A == A and anterior_B == B){
			iguales = true;
		}
		
		anterior_A = A;
		anterior_B = B;
		
		cin >> A;
	}
	
	cout << max_suma << endl;
	
	if(iguales)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
	

	return 0;
}

