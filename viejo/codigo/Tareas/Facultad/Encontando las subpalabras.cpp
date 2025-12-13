#include <set>
#include <iostream>
using namespace std;

void solve(string actual, string restantes, set<string>& lista);

int main() {
	
	string palabra, actual;
	set<string> lista;
	
	cin >> palabra;
	
	solve(actual, palabra, lista);
	
	cout << lista.size() - 1 << endl;
	
	return 0;
}

void solve(string actual, string restantes, set<string>& lista){
	
	lista.insert(actual);
	
	for(int i = 0; i < restantes.length(); i++){
		string Newactual = actual, Newrestantes = restantes;
		
		solve(Newactual += restantes[i], Newrestantes.erase(i,1), lista);
	}
}
	

/*
PERRO 
	
P E R R O

PE PR PO ER EO RR 

*/
