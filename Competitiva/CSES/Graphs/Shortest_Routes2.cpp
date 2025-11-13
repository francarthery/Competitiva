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
const int INF = 1e18, MAX_N = 500;
int N;

// Min path between every pair of nodes in directed graph
// G[i][j] initially needs weight of edge (i, j) or INF
// be careful with multiedges and loops when assigning to G
int G[MAX_N][MAX_N];
void floyd() {  // O(N^3)
  forn(k, N) forn(i, N) if (G[i][k] != INF) forn(j, N) if (G[k][j] != INF)
      G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}
bool inNegCycle(int v) { return G[v][v] < 0; }
// checks if there's a neg. cycle in path from a to b
bool hasNegCycle(int a, int b) {
  forn(i, N) if (G[a][i] != INF && G[i][i] < 0 && G[i][b] != INF) return true;
  return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int m, q, a, b, c;
    cin >> N >> m >> q;
    forn(i, m){
        cin >> a >> b >> c;
        a--; b--;
        G[a][b] = c;
    }


    
    return 0;
}