#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	
	int Am, Rm, Em, Av, Rv, Ev;
	string GANADOR;
	
	cin >> Am >> Rm >> Em >> Av >> Rv >> Ev;
	cin.ignore();
	getline(cin, GANADOR);
	
	
	if(GANADOR.size()*Em+Rm+Am*2>GANADOR.size()*Ev+Rv+Av*2)
		cout << "Vinicius";
	else if(GANADOR.size()*Em+Rm+Am*2<GANADOR.size()*Ev+Rv+Av*2)
		cout << "Matheus";
	else
		cout << "Empate";
	
	
	return 0;
	
}