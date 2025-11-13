#include <iostream>
#include <stack>
using namespace std;

int main() {
	
	stack< pair<int, int> > stc;
	pair<int, int> val;
	unsigned N;
	long long unsigned mayor = 0, i;
	
	while(cin >> N and N != 0){
		mayor = 0;
		
		for(i = 0; i < N; i++){
			val.first = i;
			cin >> val.second;
			
			//Si la pila esta vacia o el tope es menor a la barra nueva, insertamos ultimo elemento
			if(stc.empty() or stc.top().second < val.second)
				stc.push(val);
			//Si el elemento actual es mayor al tope de pila, desapilamos y calculamos areas.
			else if(stc.top().second > val.second){
				
				while(!stc.empty() and stc.top().second > val.second){
					mayor = max(mayor, stc.top().second * (i - stc.top().first));
					val.first = stc.top().first;
					stc.pop();
				}
				
				stc.push(val);
			}
		}
		
		//Calculamos los elementos que quedaron en la pila.
		while(!stc.empty()){
			mayor = max(mayor, stc.top().second * (i - stc.top().first));
			stc.pop();
		}
		
		cout << mayor << endl;
	}
	
	return 0;
}

//7 2 1 4 5 1 3 3