#include <iostream>
#include <iomanip>
using namespace std;

double raiz(int N);

int main(int argc, char *argv[]) {
	
	int N;
	
	cin >> N; 
	
	cout << fixed << setprecision(10) << raiz(N) + 3 << endl;
	
	return 0;
}

double raiz(int N){
	
	if(N == 0) return 0;
	else return 1/(6 + raiz(N - 1));
	
}
