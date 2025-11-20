#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> iil;
typedef tuple<int, int, int> iii;

const ll INF = 1e18;
vector<vector<int>> G, idx; 

struct Dijkstra {       
    vector<vector<iil>> dist;

    int N;
    Dijkstra(int n) : N(n) {}
    void run(vector<ii> &src, int evil) {  // O(|E| log |V|)
        dist = vector<vector<iil>>(N, vector<iil>(2, iil(INF, -1))); //guardo las dos distancias mas chicas a cada nodo desde dos sources distintos

        priority_queue<iii, vector<iii>, greater<iii>> Q;
        for(ii &i : src) Q.push({i.sc, i.fr, i.fr}); //cargo todos los sources. guardo el nodo desde el que comence

        while (sz(Q)) {
            auto [d, node, orig] = Q.top();
            Q.pop();
            if (d > dist[node][1].fr) continue; //si es mayor a las dos distancias

            forn(i, N) 
                if(i != evil and G[node][i] and d + G[node][i] < dist[i][1].fr) { //si es menor a la mayor de las distancias me sirve
                    if(dist[i][0].fr > d + G[node][i] and dist[i][0].sc != orig) dist[i][1] = dist[i][0], dist[i][0] = {d + G[node][i], orig};
                    else if(dist[i][0].fr > d + G[node][i] and dist[i][0].sc == orig) dist[i][0].fr = d + G[node][i];
                    else if(dist[i][1].fr > d + G[node][i] and dist[i][0].sc != orig) dist[i][1] = {d + G[node][i], orig};
                    else continue;
                    Q.push({d + G[node][i], i, orig});
                }   
        }
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b, c; cin >> n >> m;
    G.assign(n, vector<int>(n));
    idx.assign(n, vector<int>(n));
    vector<ll> rta(m, INF);
    Dijkstra dj(n);

    forn(i, m){
        cin >> a >> b >> c; a--; b--;
        G[a][b] = G[b][a] = c;
        idx[a][b] = idx[b][a] = i; 
    }

    forn(i, n){
        vector<ii> src;
        forn(j, n) if(G[i][j]) src.pb({j, G[i][j]}); //inserto todos los adyacentes a i y su dist a i
        dj.run(src, i);

        forn(j, n) {
            if(G[i][j]){
                if(dj.dist[j][0].fr != INF and dj.dist[j][0].sc != j) rta[idx[i][j]] = dj.dist[j][0].fr; //puedo ir por el mas rapido
                else if(dj.dist[j][1].fr != INF) rta[idx[i][j]] = dj.dist[j][1].fr; // voy por el segundo mas rapido
            }
        }
    }

    forn(i, m) cout << (rta[i] == INF ? -1 : rta[i]) << '\n';

    return 0;
}