#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char *argv[]) {
	
	//En esta cola los elementos se almacenan en orden usando un arbol binario.
	priority_queue<int> pq; //Declaracion
	int N;
	
	for(int i = 0; i < 8; i++){
		cin >> N;
		pq.push(N);
	}
	
	cout << pq.top() << endl; //Sera el mayor elemento de la lista
	
	
	
	//Tambien podemos mandar un comparador para que el orden sea inverso
	priority_queue<int, vector<int>, greater<int>> pqg;
	
	for(int i = 0; i < 8; i++){
		cin >> N;
		pqg.push(N);
	}
	
	cout << pqg.top() << endl; //Ahora sera el menor elemento de la lista
	
	
	return 0;
}

