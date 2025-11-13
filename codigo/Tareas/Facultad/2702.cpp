#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	char a;
	
	cin >> a;
	cout << a << endl;
	
	if (a <= 'A')
		cout << "numero" << endl;
	else
		cout << "letra" << endl;

	
	return 0;
}

