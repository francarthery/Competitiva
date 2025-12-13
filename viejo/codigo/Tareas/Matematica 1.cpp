#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	
	int metros=480;
	int metros2=480;
	string respuesta="";
	
	for(int precio=198; precio<600; precio+=9){
		
		metros2=metros2+110;
		respuesta+= to_string(metros2)+">=x>"+to_string(metros)+", "+to_string(precio)+ ", ";
		metros=metros2;
	}
	
	cout << respuesta << endl;
	return 0;
}


