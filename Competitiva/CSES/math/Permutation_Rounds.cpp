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

ll expMod(ll b, ll e, ll m) {  // O(log e)
    if (e < 0) return 0;
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
        b = b * b % m;                 // b = mulMod(b,b,m);
        e >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    const int MOD = 1e9 + 7;
    const int MAXN = 2e5 + 1;
    vector<int> criba(MAXN);
    criba[1] = 1;
    forr(i, 2, MAXN) if(!criba[i]) for(int j = i; j < MAXN; j += i) criba[j] = i;

    int n; cin >> n;
    vector<int> v(n);
    forn(i, n) cin >> v[i];

    vector<int> ciclos, vis(n);
    forn(i, n) if(!vis[i]){
        int pos = v[i] - 1, tam = 1;
        vis[i] = true;
        while(pos != i){
            vis[pos] = true;
            pos = v[pos] - 1;
            tam++;
        }
        ciclos.pb(tam);
    }

    map<int, int> factores;
    for(int p : ciclos){
        map<int, int> f;
        while(criba[p] != p){
            f[criba[p]]++;
            p /= criba[p];
        }
        f[p]++;

        for(auto i : f){
            factores[i.fr] = max(factores[i.fr], i.sc);
        }
    }

    ll rta = 1;
    for(auto i : factores) rta = rta * expMod(i.fr, i.sc, MOD) % MOD;
    cout << rta << '\n';

    return 0;
}