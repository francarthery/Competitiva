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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n; 
    const int MAXN = 1e6 + 1;
    vector<int> v(n), divs(MAXN), criba(MAXN);
    forn(i, n) cin >> v[i];

    forr(i, 2, MAXN) if(!criba[i]) for(int j = i; j <= MAXN; j += i) criba[j] = i;
    criba[1] = 1;

    ll res = 0;
    dfor(i, n){
        if(v[i] == 1) continue; //si hay mas de un 1 y no pongo esto explota todo

        vector<int> pie;
        while(criba[v[i]] != v[i]){
            if(!sz(pie) or pie.back() != criba[v[i]]) pie.pb(criba[v[i]]);
            v[i] /= criba[v[i]];
        }            
        if(!sz(pie) or pie.back() != v[i]) pie.pb(criba[v[i]]);

        forr(j, 1, (1 << sz(pie))){ //Inclusion - Exclusion. Me fijo con cuantos numeros de los de adelante mio no soy coprimo (comparto algun primo)
            ll cont = 0, num = 1;
            forn(k, sz(pie)) if(j & (1 << k)){
                cont++;
                num *= pie[k];
            }
            if(cont & 1) res += divs[num];
            else res -= divs[num];

            divs[num]++;
        }
    }

    cout << (ll(n) * (n - 1)) / 2 - res << '\n';

    return 0;
}
