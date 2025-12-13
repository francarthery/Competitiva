#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N, C;
	
	cin >> N;
	
	while(N!=0){
		C=0;
		for(int i=1; i<=N; i++)
			C=C+pow(i,2);
		cout << C << endl;
		cin >> N;
	}
	
	return 0;
}

