struct Cola{
	int primero, ultimo;
	int info[10];
};

bool encolar(Cola &, int);
bool desencolar(Cola &, int &);
bool vacia(Cola &);
void inicializar(Cola &);
void mostrar_cola(const Cola &);
