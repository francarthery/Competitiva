#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compararIntervalos(const vector<int>& a, const vector<int>& b) {
    return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
}

int main(){
	
	int N, cant_i, inicio_i, fin_i;
	bool a_contenido = false, b_contenido = false;
	
	while(cin >> N){
		cant_i = 0, inicio_i = 0, fin_i = 0;
		vector<vector<int>> intervalos(N, vector<int>(2));

		for (int i = 0; i < N; i++) {
			cin >> intervalos[i][0] >> intervalos[i][1];
		}

		sort(intervalos.begin(), intervalos.end(), compararIntervalos);

		for (int i = 0; i < N; i++) {		
			
			a_contenido = false, b_contenido = false;

			//Nos fijamos si comparte espacio con el intervalo actual
			if(intervalos[i][0] <= fin_i and intervalos[i][0] >= inicio_i)
				a_contenido = true;
			if(intervalos[i][1] <= fin_i and intervalos[i][1] >= inicio_i)
				b_contenido = true;
			

			//Si se comparte intervalo, se reduce este a la intersección y sino pasamos a uno nuevo
			if(a_contenido)
			   inicio_i = intervalos[i][0];
			if(b_contenido)
				fin_i = intervalos[i][1];
			if(!a_contenido and !b_contenido){
				if(intervalos[i][0] > inicio_i or intervalos[i][1] < fin_i){
				inicio_i = intervalos[i][0];
				fin_i = intervalos[i][1];
				cant_i++;
				}
			}
		}
		cout << cant_i << endl;
	}
	
	return 0;
}