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
    cout << '['; for(auto c : v) cout << c << ','; cout << "\b]\n";
}

typedef long long ll;
typedef pair<int, int> ii;
int n, m, d;

#define INF INT_MAX
vector<vector<int>> G;
void floyd() {  // O(N^3)
    forn(k, n) forn(i, n) if (G[i][k] != INF) forn(j, n) if (G[k][j] != INF)
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}
bool inNegCycle(int v) { return G[v][v] < 0; }

bool hasNegCycle(int a, int b) {
  forn(i, n) if (G[a][i] != INF && G[i][i] < 0 && G[i][b] != INF) return true;
  return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n >> m >> d;
    

    
    return 0;
}