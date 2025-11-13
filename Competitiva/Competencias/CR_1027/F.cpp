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

#define MAXP 10000 //Tiene que ser mayor a la raiz del mayor num a factorizar

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
void fact(ll n, map<ll, ll, greater<ll>>& f) {  // O (cant primos)
    for(int &p : primos){
        while (!(n % p)) {
            f[p]++;  // divisor found
            n /= p;
        }
    }
    if (n > 1) f[n]++;
}

int f(int n, int k){
    if(n == 1) return 0;
    map<ll, ll, greater<ll>> primos;
    fact(n, primos);
    if(primos.begin() -> fr > k) return -1; //si tengo un primo mayor que k

    int cont = 0, flag = 1;
    while(flag){ //le meto hasta que no me quede nada en el map
        flag = 0;
        int res = 1;
        forall(it, primos){
            if(it -> sc == 0) continue;
            if(k / res >= it -> fr) {
                int ma = min(it -> sc, (k / (res * (it -> fr))));
                res *= (it -> fr) * ma;
                it -> sc -= ma;
            }
        }

        for(auto i : primos) if(i.sc) flag = true;
        cont++;
    }
    return cont;
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
    while(t--){
        int x, y, k; cin >> x >> y >> k;
        int mcd = gcd(x, y);
        x /= mcd;
        y /= mcd;

        int f1 = f(x, k);
        int f2 = f(y, k);
        dbg(f1); dbg(f2);
        cout << (f1 != -1 and f2 != -1 ? f1 + f2 : -1) << '\n';
    }



    return 0;
}