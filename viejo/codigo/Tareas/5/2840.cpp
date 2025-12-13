#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	
	int R, L, V;
	
	cin >> R >> L;
	
	V=3.1415*pow(R, 3)*4/3;

	cout << L/V << endl;
	
	return 0;
}

