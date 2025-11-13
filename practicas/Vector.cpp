#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	
	vector<int> vec; // Declaracion
	int N;
	
	for(int i = 0; i < 5; i++){
		cin >> N;
		vec.push_back(N); //Insertar valores al final
	}
	
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << "  ";
	}
	
	vec.erase(vec.begin() + 2); //Eliminar un valor
	vec.insert(vec.begin() + 2, 3, 69); //Inserta 3 veces el 69 en la posicion 2 del vector
	
	cout << endl << endl;
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << "  ";
	}
	
	cout << endl << vec.front() << "  " << vec.back() << endl; //Primer y ultimo elemento
	
	return 0;
}

