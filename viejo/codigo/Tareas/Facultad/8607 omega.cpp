#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double raiz(int n, int k);

int main(int argc, char *argv[]) {
	
	int n;
	
	cin >> n;
	
	cout << fixed << setprecision(8) << 4 * raiz(n, 0) << endl;
	
	return 0;
}

double raiz(int n, int k){
	
	if(n == 0)return 0;
	else return pow(-1, k) / (2 * k + 1) + raiz(n - 1, k + 1);
}
