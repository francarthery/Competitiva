#include <bits/stdc++.h>

using namespace std;

//https://cp-algorithms.com/graph/cutpoints.html

vector< vector< int > > G;
int n;

vector<bool> visited; //Controla los nodos que fueron visitados
vector<int> tin, low; //Contienen el tiempo de visita y el nodo mas bajo al que llegamos con un backedge
set<int> ap; //Almacena los nodos que cumplen la condicion
int timer;

void dfs(int v, int p = -1){ //p indica el padre de v. En el caso de la raiz es -1 (no hay)
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;

    for(int to : G[v]){
        if(to == p) continue; //Que el hijo vuelva al padre es redundante
        if(visited[to]){ //Si el hijo ya fue visitado nos fijamos que si tiene un backedge menor al de v 
            low[v] = min(low[v], tin[to]);
        }
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]); //Nos fijamos si alguna de las ramas tiene un backedge menor al de v
            if(low[to] >= tin[v] and p != -1){ //Si el menor backedge es mayor o igual al descubrimiento de v, v es un ap
                ap.insert(v);
            }
            ++children;
        }
    }

    if(p == -1 and children > 1) //Si v es la raiz y tiene dos hijos, v es un ap
        ap.insert(v);
}

void find_cutpoints(){
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    ap.clear();
    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i); //Hacemos el recorrido en todas las componentes conexas del grafo
    }
}

int main(){

    int m, cont = 0;
    string a, b;

    while(cin >> n and n != 0){
        vector<string> c;
        G.assign(n, vector<int>());

        for(int i = 0; i < n; i++){
            cin >> a;
            c.push_back(a);
        }

        cin >> m;

        for(int i = 0; i < m; i++){
            cin >> a >> b;
            G[find(c.begin(), c.end(), a) - c.begin()].push_back(find(c.begin(), c.end(), b) - c.begin()); //Grafo no dirigido
            G[find(c.begin(), c.end(), b) - c.begin()].push_back(find(c.begin(), c.end(), a) - c.begin()); //Grafo no dirigido
        }

        find_cutpoints();

        set<string> res; //Ordeno alfabeticamente ciudades
        for(int i : ap){
            res.insert(c[i]);
        }
        
        cout << "City map #" << ++cont << ": " << ap.size() << " camera(s) found" << endl;
        for(string i : res) cout << i << endl;
        cout << endl;
    }


    return 0;
}