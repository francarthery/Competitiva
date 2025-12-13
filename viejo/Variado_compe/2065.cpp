#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> pp;

struct compare{
	bool operator()(pp a, pp b){
		if(a.first != b.first) return a.first > b.first;
		else return a.second.first > b.second.first;
	}
};

int main() {
	
	int n, m, aux = 0, x, cont;
	
	cin >> n >> m;
	vector<int> t(n);

	priority_queue<pp, vector<pp>, compare> pq; //Estructura(tiempo, (n_cajero, t_cajero))
	
	for(int i = 0; i < n; i++){
		cin >> t[i];
	}
	
	for(int i = 0; i < n; i++){
		cin >> aux;
		pq.push(make_pair(aux * t[i], make_pair(i, t[i]))); //Los primeros m clientes van con los n cajeros en orden de llegada
	}
	
	cont = n;
	while(cont < m){ //Tomamos al resto de los clientes con el cajero que se desocupo
		cin >> x;
		pp cima = pq.top();
		pq.pop();
		
		pq.push(make_pair(cima.second.second * x + cima.first, cima.second));
		cont++;
	}
	
	while(pq.size() > 1)
		pq.pop();
	
	cout << pq.top().first << endl;
	
	return 0;
}

