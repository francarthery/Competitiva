#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	
	int X,Y;
	string RESPUESTA;
	cin >> X >> Y;
	
	while(X!=Y){
		if(X>Y)
			RESPUESTA=RESPUESTA+"Decrescente\n";
		else
			RESPUESTA=RESPUESTA+"Crescente\n";
		cin >> X >> Y;}
	
	size_t tam= RESPUESTA.length(); 
	RESPUESTA.erase(tam-1);
	cout << RESPUESTA << endl;
	
	return 0;
}

	
