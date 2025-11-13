#include <iostream>
using namespace std;

bool contiene3(long long int num);
	
int main(int argc, char *argv[]) {
	
	long long int num1 = 1, num2 = 1, aux;
	int N, i = 0;
	
	while(cin >> N){
		i = 0;
		num1 = num2 = 1;
		
		while(i < N){
			aux = num1;
			num1 = num2;
			num2 += aux;
			
			if(num2 % 3 == 0 or contiene3(num2))
				i++;
		}
		
		cout << num2 << endl;
	}
	
	return 0;
}

bool contiene3(long long int num){
	
	if(num < 3)
		return false;
	else if(num % 10 == 3)
		return true;
	else
		return contiene3(num / 10);
}

