#include <iostream>

using namespace std;

int main() {
	
	int N,X,in,out;

	cin >> N;
	
	in=0;
	out=0;
	
	for(int i=0; i<N; i++){
		cin >> X;
		if(X>=10 and X<=20)
			in++;
		else
			out++;
	}
	
	cout << in << " in" <<endl;
	cout << out << " out" <<endl;
	
	return 0;
}

/* 
N: Va a decir cuantas veces se va a pedir un número
X: Va a almacenar los números introducidos
in: Si X esta en [10,20] se le suma +1 a in
out: Si X esta fuera de [10,20] se le suma +1 a out
*/
