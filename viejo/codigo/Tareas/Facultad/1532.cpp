#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N, V, suma = 0;
	bool rta;
	
	cin >> N >> V;
	
	while(N != 0 or V != 0){
		
		rta = false;
		
		for(int i = V; i > 0; i--){
			suma = 0;
			for(int j = i; j > 0; j--){
				for(int k = 0; k < j; k++){
					suma += j;
					if(suma == N){
						i = 0; j = 0; k = 0;
						rta = true;
					}
				}
			}
		}
		
		if(rta)
			cout << "possivel" << endl;
		else
			cout << "impossivel" << endl;
		
		cin >> N >> V;
	}
	
	
	return 0;
}

