#include <iostream>
#include <stack>
using namespace std;

struct Par{
	int posicion;
	int altura;
};

int main() {
	
	stack<Par> stc;
	Par val;
	unsigned N;
	long long unsigned mayor = 0, i;
	
	while(cin >> N and N != 0){
		mayor = 0;
		
		for(i = 0; i < N; i++){
			val.posicion = i;
			cin >> val.altura;
			
			//Si la pila esta vacia o el tope es menor a la barra nueva, insertamos ultimo elemento
			if(stc.empty() or stc.top().altura < val.altura)
				stc.push(val);
			//Si el elemento actual es mayor al tope de pila, desapilamos y calculamos areas.
			else if(stc.top().altura > val.altura){
				
				while(!stc.empty() and stc.top().altura > val.altura){
					mayor = max(mayor, stc.top().altura * (i - stc.top().posicion));
					val.posicion = stc.top().posicion;
					stc.pop();
				}
				
				stc.push(val);
			}
		}
		
		//Calculamos los elementos que quedaron en la pila.
		while(!stc.empty()){
			mayor = max(mayor, stc.top().altura * (i - stc.top().posicion));
			stc.pop();
		}
		
		cout << mayor << endl;
	}
	
	return 0;
}
