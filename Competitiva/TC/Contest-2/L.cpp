#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

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


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n, x;
    cin >> t;
    buscarPrimos();

    while(t--){
        cin >> n;
        int ma = 0, maxbit = 0, cont = 0;
        bool flag = false;
        vector<int> v(n);
        forn(i, n){
            cin >> x;
            if(x) flag = true;
            v[i] = x;
            ma = max(ma, x);

        }

        if(flag){
            forn(i, 30) if(ma & (1 << i)) maxbit = i; //Calculo 1 mas a la izquierda
            maxbit++;
            vector<int> bits(maxbit);
            forn(i, n){
                forn(j, maxbit) if(v[i] & (1 << j)) bits[maxbit - 1 - j]++;
            }

            //dbg(maxbit);
            //vdbg(bits);
            int mcd = 0;
            forn(i, maxbit) mcd = __gcd(mcd, bits[i]); 
    
            map<ll, ll> fac;
            vector<ll> div;
            fact(mcd, fac);
            divisores(fac, div, fac.begin());
            sort(all(div));
            
            for(ll & i : div) cout << i << ' ';
        }
        else forr(i, 1, n + 1) cout << i << ' ';

        cout << '\n';
    }
    
    return 0;
}