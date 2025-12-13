#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N;
	
	double X,DECIMALES;
	
	cin >> N;
	
	X=6;
	for(int i=0; i<N; i++){
		//DECIMALES=1/X;
		
		X=6+(1.00/6.00);
		X=1/X;
		
	}
	
	cout << fixed << setprecision(10);
	cout << X+3 << endl;
	cout << X << endl;
	return 0;
}

/* 

N=1:
3+(1/6)

N=2:
3+1/(6+1/6)

N=3;
3+1/(6+(1/(6+1/6)

N=4;
3+1/(6+(1/(6+1/(6+1/6)




*/
