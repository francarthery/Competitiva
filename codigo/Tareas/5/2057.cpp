#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int hora, d_viaje, z_hora, h_llegada;
	
	cin >> hora >> d_viaje >> z_hora;
	
	h_llegada= hora+d_viaje+z_hora;
	
	if(h_llegada>=24)
		h_llegada=h_llegada-24;
	else if(h_llegada<0)
		h_llegada=h_llegada+24;
	
	cout << h_llegada << endl;
	
	return 0;
}

