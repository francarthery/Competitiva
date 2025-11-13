#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char *argv[]) {
	
	queue<int> que;
	int N;
	
	for(int i = 0; i < 5; i++){
		cin >> N;
		que.push(N); //Insetar elemento al final de la cola.
	}
	
	cout << que.front() << endl; //Primer elemento de la cola
	cout << que.back() << endl; //Ultimo elemento de la cola
	
	que.pop(); // Eliminar primer elemento
	
	cout << endl << que.front() << endl; //Sacamos el primer elemento por lo que la cola empieza en otro
	
	return 0;
}

