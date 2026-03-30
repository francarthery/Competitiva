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

#define MAXP 1000 //Tiene que ser mayor a la raiz del mayor num a factorizar

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

vector<ll> primos;
void buscarPrimos() {
    crearCriba();
    for(int i = 2; i <= MAXP; i++) if(!criba[i]) primos.push_back(i);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    buscarPrimos();
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n), b(n), newa(n);
        forn(i, n) cin >> a[i];
        forn(i, n) cin >> b[i];
        vector<bool> did(n);

        ll cont = 0;
        newa = a;
        forn(i, n) {
            ll yo = a[i];
            ll ant = (i > 0 ? a[i-1] : 0);
            ll sig = (i < n-1 ? a[i+1] : 0);
            ll comun = gcd(yo, gcd(ant, sig));
            yo /= comun;
            ant /= comun;
            sig /= comun;
            if(ant) yo /= gcd(yo, ant);
            if(sig) yo /= gcd(yo, sig);
            if(yo > 1 and a[i] / yo <= b[i]) {
                cont++;
                did[i] = true;
                newa[i] /= yo;
            }
        }

        a = newa;
        const int MAXN = 20;
        vector<vector<int>> dp(n+1, vector<int>(MAXN));
    
        forn(i, n) {
            int ma = *max_element(all(dp[i]));
            forn(j, MAXN) dp[i+1][j] = ma+did[i];

            if(did[i]) continue;

            ll yo = a[i];
            ll ant = (i == 0 ? -1 : a[i-1]);
            ll sig = (i == n-1 ? -1 : a[i+1]);
            if(ant != -1) ant /= gcd(yo, ant);
            if(sig != -1) sig /= gcd(yo, sig);

            ll prohibido; //Primos prohibidos
            if(ant != -1 and sig != -1) prohibido = (ant / gcd(ant, sig)) * sig;
            else if(ant != -1) prohibido = ant; 
            else prohibido = sig;

            forn(j, MAXN) {
                if(a[i] * primos[j] > b[i] or prohibido % primos[j] == 0) continue; 
                forn(k, MAXN) if(j != k) dp[i+1][j] = max(dp[i+1][j], dp[i][k]+1);
            } 
        }
        forn(i, n+1) vdbg(dp[i]); 
        cout << *max_element(all(dp[n])) << '\n';
    }

    return 0;
}