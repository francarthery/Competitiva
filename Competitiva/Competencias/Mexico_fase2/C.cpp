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
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MAXP 100000 //Tiene que ser mayor a la raiz del mayor num a factorizar

int criba[MAXP + 1]; //Si criba[i] == 0, i es primo
void crearCriba() { //Busca primos hasta MAXP. O(n) casi
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

void divisores(map<ll, ll>& f, vector<ll>& divs, map<ll, ll>::iterator it, ll n = 1) {
  if (it == f.begin()) divs.clear();
  if (it == f.end()) {
    divs.pb(n);
    return;
  }
  ll p = it->fst, k = it->snd;
  ++it;
  forn(_, k + 1) divisores(f, divs, it, n), n *= p;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll q, n, t;
    buscarPrimos();
    cin >> q;
    while(q--){
        cin >> n >> t;

        if(t == 1) cout << n << '\n';
        else{ 
            map<ll, ll> f;
            vector<ll> divs;
            fact(t - 1, f);
            divisores(f, divs, f.begin());
            sort(all(divs));
            ll rta = 0;
            for(ll &i : divs) if(i <= n) rta++;
            cout << rta << '\n';
        }    
    }
    
    return 0;
}