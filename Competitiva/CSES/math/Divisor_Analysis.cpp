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
typedef pair<ll, ll> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    
    const int MOD = 1e9 + 7;
    int n, x, k; cin >> n;

    function<ll(ll, ll)> expmod = [&](ll b, ll e) -> ll{
        ll res = 1;
        while(e){
            if(e & 1) res = res * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        return res;
    };

    ll tao = 1, tao2 = 1, sum = 1, prod = 1;
    vector<ii> facts(n);
    forn(i, n){
        cin >> x >> k;
        tao = tao * (k + 1) % MOD;
        tao2 = tao2 * (k + 1) % (2 * (MOD - 1)); //calculo tao mod 2 * (m - 1) cosa de poder dividir por 2 tranquilo
        sum = sum * ((expmod(x, k + 1) - 1) * expmod(x - 1, MOD - 2) % MOD) % MOD;
        facts[i] = {x, k};
    }

    forn(i, n){
        if(tao2 % 2){ //Si tao es impar todos los exponentes son pares (cuadrado perfecto) por lo que los divido directamente
            prod = prod * expmod(facts[i].fr, (facts[i].sc / 2) * (tao2 % (MOD - 1)) % (MOD - 1)) % MOD;
        }
        else{ //sino puedo dividir a tao porque es par por lo que aprovecho que lo calcule mod 2 * (m - 1) y lo divido de una
            prod = prod * expmod(facts[i].fr, facts[i].sc * (tao2 / 2) % (MOD - 1)) % MOD;
        }
    }

    cout << tao << ' ' << sum << ' ' << prod << '\n';

    return 0;
}