#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	
	int N, contador = 0, suma = 0, max = 0, min, cant_max = 0, cant_min = 0;
	bool flag = true;
	
	cin >> N;
	min = N;
	
	while(flag){
		
		if(N != -1){
			contador++;
			suma += N;
			
			if(N > max){
				cant_max = 1;
				max = N;
			}
			else if(N == max)
			   cant_max++;
			
			if(N < min){
				cant_min = 1;
				min = N;
			}
			else if(N == min)
			   cant_min++;
			
			cin >> N;
		}
		else
			flag = false;
		
	}
	
	if(contador % 2 == 0){
		cout << fixed << setprecision(2) << (float)suma / contador << endl;
		cout << cant_max << endl;
	}
	else{
		cout << abs(max) - abs(min) << endl;
		cout << cant_min << endl;
	}
	
	return 0;
}

