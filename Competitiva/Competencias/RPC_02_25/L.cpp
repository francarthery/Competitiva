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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<long double, int> ii;
typedef tuple<long double, long double, int> iii;

int t;
const ll INF = 1e18;

struct Dijkstra {        
    vector<vector<iii>> G;  
    vector<long double> dist; //guardo tiempo

    int N;
    Dijkstra(int n) : G(n), N(n) {}
    void addEdge(int a, int b, long double w1, long double w2) { //extremos, t1, t2
        G[a].pb({w1, w2, b}); 
        G[b].pb({w1, w2, a}); 
    }
    void run(int src) {  // O(|E| log |V|)

        dist = vector<long double>(N, INF);
        priority_queue<ii, vector<ii>, greater<ii>> Q;
        Q.push({0, src}), dist[src] = 0; //Tiempo de llegada, nodo

        while (sz(Q)) {
            auto [d, node] = Q.top();
            Q.pop();
            if (d > dist[node]) continue;

            forall(it, G[node]){
                long double ti = get<0>(*it); //distancia a node + largo nodo yendo lento
                if(d >= t) ti = get<1>(*it); //Si llegue a node en mas de t, voy rapido desde ahi
                else if(d + get<0>(*it) > t){ //paso a ir rapido en el medio
                    ti = (1 - ((t - d) / get<0>(*it))) * get<1>(*it) + (t - d);
                }

                if(d + ti < dist[get<2>(*it)]) {
                    dist[get<2>(*it)] = d + ti;
                    Q.push({dist[get<2>(*it)], get<2>(*it)});
                }   
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

    int n, m, a, b, c, v1, v2;
    cin >> n >> m >> t;
    Dijkstra dj(n);

    forn(i, m){
        cin >> a >> b >> c >> v1 >> v2; 
        a--; b--;
        dj.addEdge(a, b, (long double)c / v1, (long double)c / v2);
    }

    dj.run(0);
    //vdbg(dj.dist);
    cout << fixed << setprecision(6) << dj.dist[n - 1] << '\n';


    return 0;
}