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

    int t, n, d, k, a, b;
    cin >> t;
    while(t--){
        cin >> n >> d >> k;
        vector<pair<int, ii>> ev(2 * k);
        int cont = 0, ma = 0, mi = INT_MAX, posmi, posma;
        forn(i, k){
            cin >> a >> b;
            ev[2 * i] = {a, {0, i}}; // 0 inicia
            ev[2 * i + 1] = {b, {1, i}};
        }
        sort(rall(ev));
        set<int> ind;
        set<ii> val;
        forr(i, 1, n + 1){
            while(ev.back().fr == i){
                if(ev.back().sc.fr == 0) ind.insert(ev.back().sc.sc); 
                else val.insert({i, ev.back().sc.sc});
                ev.pop_back();
            }
            while(!val.empty() and val.begin() -> fr < i - d + 1){ //Si se me salio de la ventana
                ind.erase(val.begin() -> sc);
                val.erase(val.begin());
            }
            if(i >= d and sz(ind) > ma){
                ma = sz(ind);
                posma = i;
            }
            if(i >= d and sz(ind) < mi){
                mi = sz(ind);
                posmi = i;
            }
        }

        cout << posma - d + 1 << ' ' << posmi - d + 1 << '\n';
    }
    
    
    return 0;
}