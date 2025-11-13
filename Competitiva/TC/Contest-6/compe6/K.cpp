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

#define MAXP 1000100 //Tiene que ser mayor a la raiz del mayor num a factorizar

int criba[MAXP + 1]; //Si criba[i] == 0, i es primo
void crearCriba() { //Busca primos hasta MAXP
    int w[] = {4, 2, 4, 2, 4, 6, 2, 6};
    for (int p = 25; p <= MAXP; p += 10) criba[p] = 5;
    for (int p = 9; p <= MAXP; p += 6) criba[p] = 3;
    for (int p = 4; p <= MAXP; p += 2) criba[p] = 2;
    for (int p = 7, cur = 0; p * p <= MAXP; p += w[cur++ & 7])
    if (!criba[p])
        for (int j = p * p; j <= MAXP; j += (p << 1))
        if (!criba[j]) criba[j] = p;
}

vector<int> primos;
void buscarPrimos() {
    crearCriba();
    for(int i = 2; i <= MAXP; i++) if(!criba[i]) primos.push_back(i);
}

// factoriza bien numeros hasta MAXP^2, llamar a buscarPrimos antes
void fact(ll n, map<ll, ll>& f) {  // O (cant primos)
    for(int &p : primos){
        while (!(n % p)) {
            f[p]++;  // divisor found
            n /= p;
        }
    }
    if (n > 1) f[n]++;
}
void fact2(ll n, map<ll, ll>& f) {  // O (lg n)
    while (criba[n]) {
        f[criba[n]]++;
        n /= criba[n];
    }
    if (n > 1) f[n]++;
}

// Usar asi: divisores(fac, divs, fac.begin()); NO ESTA ORDENADO
void divisores(map<ll, ll>& f, vector<ll>& divs, map<ll, ll>::iterator it, ll n = 1) {
    if (it == f.begin()) divs.clear();
    if (it == f.end()) {
        divs.pb(n);
        return;
    }
    ll p = it->fr, k = it->sc;
    ++it;
    forn(_, k + 1) divisores(f, divs, it, n), n *= p;
}

ll cantDivs(map<ll, ll>& f) {
    ll ret = 1;
    forall(it, f) ret *= (it->second + 1);
    return ret;
}

ll sumDivs(map<ll, ll>& f) {
    ll ret = 1;
    forall(it, f) {
        ll pot = 1, aux = 0;
        forn(i, it->sc + 1) aux += pot, pot *= it->fr;
        ret *= aux;
    }
    return ret;
}

ll eulerPhi(ll n) {  // con criba: O(lg n)
    map<ll, ll> f;
    fact2(n, f);
    ll ret = n;
    forall(it, f) ret -= ret / it->first;
    return ret;
}
ll eulerPhi2(ll n) {  // O (sqrt n)
    ll r = n;
    forr(i, 2, n + 1) {
        if ((ll)i * i > n) break;
        if (n % i == 0) {
            while (n % i == 0) n /= i;
                r -= r / i;
        }
    }
    if (n != 1) r -= r / n;
    return r;
}

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    ll ans = 0;

    buscarPrimos();
    forr(i, 1, n - 1){
        vector<ll> divs;
        map<ll, ll> f;
        fact2(n - i, f);
        divisores(f, divs, f.begin());

        for(ll j : divs){
            if(j == n - i) continue;
            ans = (ans + (ll)lcm(i, j) * eulerPhi((n - i) / j)) % MOD;
        }
    }

    cout << ans << '\n';


    return 0;
}