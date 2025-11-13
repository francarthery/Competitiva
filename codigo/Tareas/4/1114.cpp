#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	string PASSWORD;
	
	cin >> PASSWORD;
	
	while(PASSWORD!="2002"){
		cout << "Senha Invalida" <<endl;
		cin >> PASSWORD;
	}
	cout << "Acesso Permitido" <<endl;
	
	
	return 0;
}

