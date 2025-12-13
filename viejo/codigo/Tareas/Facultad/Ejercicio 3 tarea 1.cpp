#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int a, b;
	
	cout << "Ingrese cantidad de mujeres: ";
	cin >> a;
	cout << "Ingrese cantidad de hombres: ";
	cin >> b;
	
	cout << "En la comisión hay un " << a*100/(a+b) << "% de mujeres y un " << b*100/(a+b) << "% de varones." << endl; 
	
	
	return 0;
}

