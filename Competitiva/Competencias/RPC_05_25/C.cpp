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

    int q; cin >> q;
    vector<ll> sums(43), parcial(43); //log2(1e13) me paso por las dudas
    sums[1] = 1; //sums[i] tiene lo que suman los primeros 2^i - 1 numeros
    parcial[1] = 1;
    forr(i, 2, sz(sums)) {
        ll res = parcial[i - 1] * 2ll + 3ll * (1ll << (i - 2)); //2^i es el tam del rango
        parcial[i] = res;
        sums[i] = sums[i - 1] + res;
    }

    function<ll(ll)> suma = [&](ll lim) -> ll {
        ll lg2 = __lg(lim);
        ll tot = sums[lg2], num = lg2 + 1;
        lim -= (1ll << lg2) - 1;
        dfor(i, 43){
            if(lim & (1ll << i)) {
                tot += parcial[i + 1] + (1ll << i) * ((num - (i + 1)));
                num++;
            }
        }
        return tot;
    };

    while(q--){
        ll l, r; cin >> l >> r;
        if(!r) {
            cout << 0 << '\n';
            continue;
        }
        ll tot = suma(r);

        if(l <= 1) {
            cout << tot << '\n';
            continue;
        }
        ll resto = suma(l - 1);
        
        cout << tot - resto << '\n';
    }

    return 0;
}