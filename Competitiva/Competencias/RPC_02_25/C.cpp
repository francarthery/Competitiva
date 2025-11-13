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
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> val(n), dist(n, 1e9), gr(n);

    forn(i, m){
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
        gr[a]++;
        gr[b]++;
    }
    
    int exp = __lg(n);
    bool flag = !(n & (n - 1)); //n = 2^k 
    forn(i, n) if(gr[i] != exp) flag = false;

    int aux = 1;
    for(int &u : g[0]){
        val[u] = aux;
        aux *= 2;
    }

    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while(sz(q)){
        int s = q.front();
        q.pop();

        for(int &u : g[s]){
            if(dist[u] > dist[s]){
                if(dist[u] == 1e9){ //Nunca llegue a u
                    q.push(u);
                    dist[u] = dist[s] + 1;
                }    
                val[u] |= val[s];
            }
        }
    }

    forn(i, n){
        for(int &u : g[i]) if(abs(val[u] - val[i]) & (abs(val[u] - val[i]) - 1)) flag = false; //si no se llevan una pot de 2
    }

    cout << (flag ? "yes" : "no") << '\n';
    
    return 0;
}