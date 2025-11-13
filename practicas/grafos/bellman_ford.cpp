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
typedef pair<pair<int, int>, int> edge;

int n, m, v;
vector<edge> g;
const int INF = 1e9;

void bellman(){ //O(nm). Usa lista de aristas.
    vector<int> d(n, INF);
    d[v] = 0;
    for (int i = 0; i < n - 1; i++) //k, cant de aristas que puedo recorrer
        for (edge e : g)
            if (d[e.fr.fr] < INF)
                d[e.fr.sc] = min(d[e.fr.sc], d[e.fr.fr] + e.sc);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif


    
    return 0;
}