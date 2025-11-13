#include <iostream>
using namespace std;

bool isPrime(long long N){ //O(sqrt(n))
	if(N == 2) return true;
	if(N < 2 or N % 2 == 0) return false;
	for(int i = 3; i * i <= N; i += 2)
		if(N % i == 0) return false;
	
	return true;
}

int main() {
	
	int N;
	cin >> N;
	
	if(isPrime(N)) cout << "El numero es primo" << endl;
	else cout << "El numero no es primo" << endl;
	
	return 0;
}

