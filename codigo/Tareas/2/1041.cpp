#include <iostream>

using namespace std;

int main() {
	
	int X,Y;
	
	cin >> X >> Y;
	
	
	if(X<0 and Y<0)
		cout << "terceiro" << endl;
	else
		if(X>0 and Y>0)
			cout << "primeiro" << endl;
		else
			if(X>0 and Y<0)
				cout << "cuarto" << endl;
			else
				if(X<0 and Y>0)
					cout << "segundo" << endl;
				else 
					cout << "Origem" << endl;
	
	
		

	return 0;
}
