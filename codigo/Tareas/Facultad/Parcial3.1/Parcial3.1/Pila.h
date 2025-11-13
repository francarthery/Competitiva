#include <iostream>
using namespace std;

struct Oracion{
	string oracion;
	int ordinal;
};

struct Pila{
	Oracion contenido[100];
	int final;
};

bool desapilar(Pila &, Oracion &);
bool vacia(Pila &);
