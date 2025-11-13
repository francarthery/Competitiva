#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int edad, dias, meses, anos;
	
	cin >> edad;
	
	anos = edad/365;
	meses = (edad-anos*365)/30;
	dias = edad-((anos*365)+(meses*30));
	
	cout << anos << " ano(s)" << endl;
	cout << meses << " mes(es)" << endl;
	cout << dias << " dia(s)" << endl;
	
	return 0;
}

