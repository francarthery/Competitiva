#include <iostream>
#include <set>
using namespace std;

int main(int argc, char *argv[]) {
	int N;
	set<int> miset;
	
	for(int i = 0; i < 10; i++){
		cin >> N;
		miset.insert(N);
	}
	
	
	
	cout << "El tamanio del conjunto es " << miset.size() << endl;
	cout << "Los elementos del conjunto son: ";
	
	for(int elemento : miset){
		cout << elemento << " ";
	}
	
	
	cout << "Introduzca elemento a eliminar: ";
	cin >> N;
	if(miset.find(N) != miset.end())
		miset.erase(N);
	else
		cout << "El elemento no esta en el conjunto" << endl;
	
	cout << endl;
	for(int elemento : miset){
		cout << elemento << " ";
	}
	cout << endl << endl;
	
	return 0;
}

