#include <bits/stdc++.h>

using namespace std;

vector<int> padre; //TAM = cant nodos

int Find(int x){
    if(x == padre[x]) return x;  
    else return padre[x] = Find(padre[x]);
}

void Union(int x, int y){ //INICIALIZAR forn(i, n) padre[i] = i;
    int u = Find(x), v = Find(y);
    if(u != v){
        if(u < v) padre[u] = v;
        else padre[v] = u;
    }    
}

int main(){

    int n;
    cin >> n;

    padre.resize(n);
    for(int i = 0; i < n; i++) padre[i] = i; //Inicialmente cada nodo es su propio padre

    return 0;
}

