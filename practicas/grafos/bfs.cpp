#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

vector<vector<int>> g; //Lista de adyacencia.
vector<int> vis; //INICIALIZAR en -1. t visita

void bfs(int s){
    int u;
    queue<int> q;
    q.push(s);
    vis[s] = 0; //La raiz es visitada en tiempo 0

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(auto &i : g[u]){
            if(vis[i] == -1){
                q.push(i);
                vis[i] = vis[u] + 1;
            }
        }
    }
}

int main(){

    int n, m, a, b; 
    cin >> n >> m;
    g.resize(n);
    vis.assign(n, -1);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b); //Camino de A a B en grafo dirigido
    }

    bfs(5);

    return 0;
}