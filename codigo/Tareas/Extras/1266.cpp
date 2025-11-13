#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N;
	
	while(cin >> N and N != 0){
		bool *t = new bool[N];
		bool flag = false;
		int cont = 0, rta = 0, inicio = -1;
		
		for(int i = 0; i < N; i++){
			cin >> t[i];
			if(!flag and t[i] == 1){
				inicio = i;
				flag = true;
			}
		}
		
		flag = false;
		
		if(inicio == -1)
			rta = N / 2 + N % 2;
		else{
			for(int i = (inicio + 1) % N; i != inicio; i = (i + 1) % N){
				if(!flag and t[i] == 0){
					cont = 1;
					flag = true;
				}
				else if(flag and t[i] == 0)
					cont++;
				else if(flag and t[i] != 0){
					flag = false;
					rta += cont / 2;
				}
			}
		}
		
		if(flag)
			rta += cont / 2;
		
		cout << rta << endl;
	}
	
	return 0;
}
