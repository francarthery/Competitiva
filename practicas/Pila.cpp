#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char *argv[]) {
	
	stack<int> stc;
	int N;
	
	for(int i = 0; i < 10; i++){
		cin >> N;
		stc.push(N); //Coloca un elemento en el tope de la pila.
	}
	
	for(int i = 0; i < 10; i++){
		cout << stc.top() << "  "; //Muestra el elemento de la cima de la pila.
		stc.pop(); //Saca el ultimo elemento
	}
	
	return 0;
}

