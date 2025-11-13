#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> vis;

void dfs(int s){
    if(vis[s]) return;
    vis[s] = true;

    for(auto &i : g[s]){
        dfs(i);
    }
}

int main(){

    int n, m, a, b; 
    cin >> n >> m;
    g.resize(n);
    vis.resize(n);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b); //Grafo dirigido
    }
    
    dfs(1);

    return 0;
}
