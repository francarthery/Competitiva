#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string HUESOS,TIPO,ALIMENTO;
	
	cin >> HUESOS >> TIPO >> ALIMENTO;
	
	if(HUESOS=="vertebrado")
		if(TIPO=="ave")
			if(ALIMENTO=="carnivoro")
				cout << "aguia" <<endl;
			else
				cout << "pomba" <<endl;
		else
			if(ALIMENTO=="onivoro")
				cout << "homem" <<endl;
			else
				cout << "vaca" <<endl;
	else
		if(TIPO=="inseto")
			if(ALIMENTO=="hematofago")
				cout << "pulga" <<endl;
			else
				cout << "lagarta" <<endl;
		else
			if(ALIMENTO=="hematofago")
				cout << "sanguessuga" <<endl;
			else
				cout << "minhoca" <<endl;
		
	
	return 0;
}
