#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	
	setlocale(LC_ALL, "spanish");
	string texto;

	getline(cin, texto);

	cout << texto << endl;
	cout << "ñandu" << endl;

	if (texto == "ñ")
		cout << "Epicardo" << endl;
	else
		cout << "Fua" << endl;

	return 0;
}