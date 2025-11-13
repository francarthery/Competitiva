//https://cp-algorithms.com/graph/strongly-connected-components.html

#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > G, GT;
vector<bool> visited;
vector<int> order;
set<int> component;

void dfs1(int v){
    visited[v] = true;

    for(auto u : G[v])
        if(!visited[u])
            dfs1(u);
    
    order.push_back(v); //Mantenemos los vertices ordenados por tiempo de salida del DFS
}

void dfs2(int v){
    visited[v] = true;
    component.insert(v); //Añadimos los vertices que componen la SCC

    for(auto u : GT[v]) //Dado que recorremos el grafo traspuesto, solo podemos alcanzar a los vertices de la SCC
        if(!visited[u])
            dfs2(u);
}

int main(){
    
    int n, m, a, b, cont = 0;
    vector< set<int> > components; //Contiene los elementos de cada componente conexa
    cin >> n >> m;

    G.assign(n, vector<int>());
    GT.assign(n, vector<int>());

    for(int i = 0; i < m; i++){
        cin >> a >> b; //Cargamos grafo
        G[a].push_back(b);
        GT[b].push_back(a);
    }

    visited.assign(n, false); //inicialmente ningun vertice fue visitado

    for(int i = 0; i < n; i++)
        if(!visited[i]) //Visitamos todos los vertices del grafo
            dfs1(i);

    visited.assign(n, false);
    reverse(order.begin(), order.end()); //invertimos vector para que el ultimo del que se salio este primero

    for(auto v : order)
        if(!visited[v]){
            dfs2(v);
            cont++; // Cantidad de componentes conexas
            components.push_back(component);
            component.clear();
        }

    cout << "Hay " << cont << " componentes fuertemente conexas:" << endl;
    for(auto i : components){
        for(int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}