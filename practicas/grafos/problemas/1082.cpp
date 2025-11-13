#include <bits/stdc++.h>

using namespace std;

int padre[26];

int Find(int nodo){
    if(padre[nodo] == nodo) return nodo;
    else{
        return padre[nodo] = Find(padre[nodo]); //Path compression
    }
}

void Union(int i, int j){
    i = Find(i); //Igualamos i a su padre
    j = Find(j);

    if(i != j) j > i ? padre[j] = i : padre[i] = j; //Unimos los conjuntos. Siempre queda el menor como raiz.
}

int main(){

    int n, v, e;
    char a, b;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v >> e; 

        for(int j = 0; j < v; j++){ 
            padre[j] = j; //Cada nodo al principio es su propio padre
        }

        for(int j = 0; j < e; j++){ //Ingresan los arcos
            cin >> a >> b;
            Union(int(a - 'a'), int(b - 'a')); 
        }

        //Nos fijamos cuantos elementos distintos quedaron en padres[]
        map< int, vector<int> > conjuntos; //padre, hijos

        for(int j = 0; j < v; j++){
            conjuntos[Find(j)].push_back(j);
        }

        cout << "Case #" << i + 1 << ":" << endl;
        for(auto i : conjuntos){
            for(auto j : i.second){
                cout << char(j + 'a') << ",";
            }
            cout << endl;
        }
        cout << conjuntos.size() << " connected components" << endl << endl;

    }


    return 0;
}