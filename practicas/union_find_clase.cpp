// C++ implementation of disjoint set
#include <bits/stdc++.h>
using namespace std;

class DisjSet {
	int *rank, *parent, n;

public:
    //Constructor para crear e inicializar los conjuntos de n items
	DisjSet(int n)
	{
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}

	// Se toma cada nodo como un conjunto individual y se inicializan los arrays
	void makeSet()
	{
		for (int i = 0; i < n; i++) {
			parent[i] = i;
            rank[i] = 0;
		}
	}

	// Encuentra padre del conjunto al que pertenece el item x
	int find(int x)
	{
		if (parent[x] != x) {
			// Si x no es su propio padre, No es el padre de su conjunto
			parent[x] = find(parent[x]);
		}

		return parent[x];
	}


	// Se unen dos conjuntos teniendo en cuenta rank[] es decir el la altura de cada uno
	void Union(int x, int y)
	{
		// Se encuentra a los representantes de x e y
		int xset = find(x);
		int yset = find(y);

		// Se verifica que no pertenezcan al mismo conjunto
		if (xset == yset)
			return;

		// Si las alturas son distintas el mas pequeño va bajo el grande
		if (rank[xset] < rank[yset]) {
			parent[xset] = yset;
		}
		else if (rank[xset] > rank[yset]) {
			parent[yset] = xset;
		}

		// Si las alturas son iguales se va a incrementar la altura del conjunto en 1
		else {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}
};

// Driver Code
int main()
{
	// Function Call
	DisjSet obj(5);
	obj.Union(0, 2);
	obj.Union(4, 2);
	obj.Union(3, 1);

	if (obj.find(4) == obj.find(0))
		cout << "Yes\n";
	else
		cout << "No\n";
	if (obj.find(1) == obj.find(0))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}
