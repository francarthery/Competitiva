struct Componente{
	char palabra[20];
	bool esCP;
};

struct Estadistico{
	Componente contenido;
	int repeticiones
};

struct Cola{
	Estadistico info[50];
	int principio, final;
};

bool desapilar(Cola & cola1, Estadistico & valor){
	
	if(vacia(cola1)){
		return false;
	}
	else{
		valor = cola1.info[cola1.principio];
		cola1.principio = (cola1.principio + 1) % 100;
	}
}

bool vacia(const Cola & cola1){
	return (cola1.principio == cola1.final);
}
