#include <iostream>
#include <set>
using namespace std;

int main(int argc, char *argv[]) {
	
	//Contenedor que contiene un conjunto ordenado de objetos unicos
	//Para los datos primitivos, existen comparadores por defecto, sino hay que crearlo
	
	set<int> conj;
	int N;
	
	for(int i = 0; i < 8; i++){
		cin >> N;
		conj.insert(N);
	}
	
	for(auto i : conj)
		cout << i << "  "; //Mostrar elementos del conjunto
	
	conj.erase(0); // Eliminara ese elemento si es que lo encuentra
	
	
	
	//En el set a los iteradores solo se le puede sumar o restar 1 por lo que se usa advance
	auto i_beg = conj.begin();
	advance(i_beg, 2); //Movemos al iterador al indice 2. es como hacer i_beg += 2
	
	auto i_end = conj.begin();
	advance(i_end, 4);
	
	conj.erase(i_beg, i_end); //Elimino los elementos en [i_beg, i_end]
	
	
	for(auto i : conj)
		cout << i << "  ";
	
	cout << endl << conj.count(-12) << endl; //Devuelve 1 si el valor esta y 0 si no.
	
	auto it = conj.find(-12); //Devuelve un iterador a ese elemento si es que esta.
	
	auto it2 = conj.lower_bound(-12); //Devuelve un iterador al primer elemento no menor al valor
	
	return 0;
}

