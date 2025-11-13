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

vector<pair<int, pair<int,int>>> grafo;
vector<pair<int, int>> lider; //(padre, cant_hijos)

int Find(int x){
    if(x == lider[x].first) return x;
    else return lider[x].first = Find(lider[x].first);
}

void Union(int x, int y){
    int u = Find(x), v = Find(y);

    if(u != v){
        if(u > v){
            lider[u].first = v;
            lider[v].second += lider[u].second;
        }
        else{
            lider[v].first = u;
            lider[u].second += lider[v].second;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, k, a, b, p, maxv = 0;
    cin >> n >> m >> k;

    grafo.resize(m + 1);
    lider.resize(n + 1);
    forr(i, 1, n + 1) lider[i] = {i, 1};

    forn(i, m){
        cin >> a >> b >> p;
        grafo[i] = {p, {a, b}};
        maxv = max(maxv, p); //Max tiempo
    }
    sort(grafo.rbegin(), grafo.rend());
    maxv++;
    
    forn(i, maxv){
        while(!grafo.empty() and grafo.back().first == i){
            Union(grafo.back().second.first, grafo.back().second.second);
            grafo.pop_back();
        }
    
        if(lider[1].second >= k){
            cout << i << '\n';
            break;
        }
        
    }
    
    return 0;
}