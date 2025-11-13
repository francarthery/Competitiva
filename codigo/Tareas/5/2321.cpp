#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	//"a" y "b" distinguen al rectángulo, 1 y 2 el punto dentro de la figura.
	int xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2;
	
	cin >> xa1 >> ya1 >> xa2 >> ya2 >> xb1 >> yb1 >> xb2 >> yb2;
	
	if(xa2>=xb1 and xb1>=xa1)
		cout << "1" << endl;
	else if(xa2>=xb2 and xb2>=xa1)
		cout << "1" << endl;
	else 
		cout << "0" << endl;
	return 0;
}

