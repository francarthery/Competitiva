#include <iostream>
using namespace std;

int main() {
	
	int a, b, c;
	
	cout << "Ingrese el código de desactivación de la bomba: ";
	
	cin >> a >> b >> c;
	
	a = a + a%10;
	b = b + b%10;
	c = c + c%10;
	
	
	cout << "El código de desactivación real es " << c << "-" << b << "-" << a; 
	
	return 0;
}

