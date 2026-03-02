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

ll expMod(ll b, ll e) {  // O(log e)
    if (e < 0) return 0;
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * b;  // ret = mulMod(ret,b,m); //if needed
        b = b * b;                 // b = mulMod(b,b,m);
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

    int t; cin >> t;
    crearCriba();
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];

        bool flag = false;
        ll ma = -1;

        forr(i, 0, n){ 
            map<ll, ll> f;  
            fact2(v[i], f);

            if(sz(f) > 1) flag = true;
            
            if((f.begin()) -> fr < ma) flag = true;
            ma = max(ma, (f.begin()) -> fr);
        }

        bool check = true;
        forn(i, n - 1) if(v[i] > v[i + 1]) check = false;

        cout << (!check and flag ? "Alice" : "Bob") << '\n';
    }

    return 0;
}