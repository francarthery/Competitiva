#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > G, GT;
vector<int> visitado;
int cont;

void dfs1(int nodo){
    visitado[nodo] = true;
    cont++;

    for(int i = 0; i < G[nodo].size(); i++){
        if(!visitado[G[nodo][i]])
            dfs1(G[nodo][i]);
    }
}

void dfs2(int nodo){
    visitado[nodo] = true;
    cont++;

    for(int i = 0; i < GT[nodo].size(); i++){
        if(!visitado[GT[nodo][i]])
            dfs2(GT[nodo][i]);
    }
}

int main(){

    int n, m, a, b, p;
    while(cin >> n >> m and (n != 0 or m != 0)){
        G.assign(n, vector<int>());
        GT.assign(n, vector<int>());
        visitado.assign(n, false);

        for(int i = 0; i < m; i++){ //Pedimos grafos
            cin >> a >> b >> p;
            G[--a].push_back(--b);
            GT[b].push_back(a);
            if(p == 2){
                G[b].push_back(a);
                GT[a].push_back(b);
            }
        }

        cont = 0;
        dfs1(0);

        if(cont == n){
            cont = 0;
            visitado.assign(n, false);

            dfs2(0);

            if(cont == n)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else
            cout << 0 << endl;

    }

    return 0;
}