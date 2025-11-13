#include <iostream>
using namespace std;

int mcd(int x, int y){ //O(log(n)) siendo n = (min(x, y))
	if(y == 0) return x;
	else return mcd(y, x % y);
}
	
int mcm(int x, int y){
	return x * y / mcd(x, y);
}

int main() {
	
	int x, y;
	//Se puede usar las funciones de c++ gcd y lcm
	
	cin >> x >> y;
	
	cout << mcd(x, y) << endl;
	cout << mcm(x, y) << endl;
	
	return 0;
}

