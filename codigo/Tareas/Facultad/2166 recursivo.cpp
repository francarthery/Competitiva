#include <iostream>
#include <iomanip>
using namespace std;

double raiz(int n);

int main(int argc, char *argv[]) {
	
	int n;
	
	cin >> n;
	
	cout << fixed << setprecision(10) << raiz(n)+1 << endl;
	
	return 0;
}

double raiz(int n){
	
	if(n == 0)return 0;
	else return 1/(2 + raiz(n-1));
}
