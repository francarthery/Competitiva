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

    int t; cin >> t;
    while(t--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        vector<int> a(x), b(y);
        vector<ii> numeros(n+m+1);
        forn(i, x) {
            cin >> a[i];
            numeros[a[i]].first = 1;
        }
        forn(i, y) {
            cin >> b[i];
            numeros[b[i]].second = 1;
        }
        
        set<int> pusea, puseb, swp, nopudea;
        dfor(i, sz(numeros)) {
            if(numeros[i].first) { //esta en filas
                if(sz(pusea) < n-1) {
                    pusea.insert(i);
                    if(numeros[i].second) swp.insert(i); //lo podria poner en b
                }
                else if(numeros[i].second and sz(puseb) < m-1) puseb.insert(i); //pongo en b
                else nopudea.insert(i);
            }
            else if(numeros[i].second and sz(puseb) < m-1) puseb.insert(i); //exclusivo de columnas
        }

        while(sz(swp) and sz(nopudea)) {
            int i = *swp.rbegin();
            if(sz(puseb) < m-1 or sz(puseb) and *puseb.begin() < *nopudea.rbegin()) {
                if(sz(puseb) == m-1){
                    puseb.erase(puseb.begin());
                }
                puseb.insert(i);
                pusea.erase(i);

                pusea.insert(*nopudea.rbegin());
                nopudea.erase(--nopudea.end());
                
                swp.erase(i);
            }
            else break;
        }

        ll sum = 0;
        for(auto i : swp) if(!pusea.count(i) and !puseb.count(i)) sum = max(sum, (ll)i);
        forn(i, n+m+1) if((numeros[i].first or numeros[i].second) and !pusea.count(i) and !puseb.count(i)) sum = max(sum, (ll)i);
        for(auto i : pusea) sum += i;
        for(auto i : puseb) sum += i;

        cout << sum << '\n';
    }

    return 0;
}