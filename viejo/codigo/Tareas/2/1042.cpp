#include <iostream>

using namespace std;

int main() {
	
	int X,Y,Z;
	
	cin >> X >> Y >> Z;
	
	if(X>Y and X>Z)
		if(Y>Z)
			cout << Z << "\n" << Y << "\n" << X <<endl;
		else
			cout << Y << "\n" << Z << "\n" << X <<endl;
		
	else if(Y>X and Y>Z)
		if(X>Z)
			cout << Z << "\n" << X << "\n" << Y <<endl;
		else
			cout << X << "\n" << Z << "\n" << Y <<endl;
	else
		if(X>Y)
			cout << Y << "\n" << X << "\n" << Z <<endl;
		else
			cout << X << "\n" << Y << "\n" << Z <<endl;
	
	cout << "\n" << X << "\n" << Y << "\n" << Z <<endl;

	return 0;
}
