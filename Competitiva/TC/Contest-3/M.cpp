#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

vector<vector<int>> g;
vector<ii> g3;
vector<int> visitado, vis2, g2;

void dfs1(int s, int col){ //Pinta de un color a una componente conexa
    visitado[s] = col;

    for(int &u: g[s]){
        if(visitado[u] == -1){
            dfs1(u, col);
        }    
    }
}

void dfs2(int s){ //Calcula las aristas a usar para formar una componente conexa
    vis2[s] = 1;

    for(int &u: g[s]){
        if(vis2[u] == 0){
            g3.pb({s, u}); //Cargo aristas que son necesarias
            dfs2(u);
        }    
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, d, x, y, cont = 0;
    cin >> n >> m >> d;
    visitado.assign(n, -1); //Colores de componentes
    vis2.resize(n); 
    g.resize(n);
    unordered_set<int> s, s2;

    forn(i, m){
        cin >> x >> y;
        --x; --y;
        if(x != 0 and y != 0){
            g[x].pb(y);
            g[y].pb(x);
        }
        else g2.pb(max(x, y)); //Las aristas que pasan por el nodo 1 se guardan aparte
    }

    forn(i, n) {
        if(visitado[i] == -1) {
            dfs1(i, i); //Pinto cada componente de un color
            cont++; //Cantidad de componentes conexas
        }
    }

    if(cont - 1 <= d and g2.size() >= d){ //Tengo que tener maximo d + 1 componentes conexas y el grado de 1 debe ser al menos d
        vis2[0] = 1; //Parti desde el nodo 1 asi que lo cuento como visitado

        int j = 0, k = 0;
        while(k < cont - 1 or ((k >= cont - 1 or g2.size() - j <= d - k) and k < d) and j < g2.size()){ //Magia
            if(s.find(visitado[g2[j]]) == s.end() or ((k >= cont - 1 or g2.size() - j <= d - k) and k < d)){ 
                s.insert(visitado[g2[j]]);
                s2.insert(g2[j]);
                vis2[g2[j]] = 1;
                g3.pb({0, g2[j]}); //Cargo las aristas que pasan por nodo 1 que me sirven
                g2[j] = -1;
                k++;
            }
            j++;
        }

        for(int c : s2) dfs2(c); //Tiro dfs desde cada nodo al que alcance por si quedaron nodos sin conectar

        cout << "YES\n";
        for(auto &[x, y] : g3) cout << x + 1 << ' ' << y + 1 << '\n';
    }
    else cout << "NO\n";

    return 0;
}