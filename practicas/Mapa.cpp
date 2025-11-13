#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
	
	//Contenedor de pares de llaves y valores. Las llaves son unicas
	map<char, int> mapa; //Declaracion
	
	//Formas de insertar elemento
	mapa.insert(make_pair('a', 10));
	mapa['b'] = 2; //Se accede a la llave con corchetes. Si no existe se crea nueva.
	
	for(auto i : mapa)
		cout << i.first << "  " << i.second << endl; //Mostrar elementos mapa;
	
	//Un uso muy comun es para calcular frecuencia de elementos. Si hacemos:
	mapa['c']++; //Si 'c' esta se incrementara. Sino se creara una nueva llave y el valor sera 1
	
	return 0;
}

