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
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool isPrime(ll N){ //O(sqrt(n))
    if(N == 2) return true;
    if(N < 2 or N % 2 == 0) return false;
    for(int i = 3; i * i <= N; i += 2)
        if(N % i == 0) return false;

    return true;
}

#define MAXP 100000  // no necesariamente primo
int criba[MAXP + 1];
void crearCriba() {
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
  forr(i, 2, MAXP + 1) if (!criba[i]) primos.push_back(i);
}

// factoriza bien numeros hasta MAXP^2, llamar a buscarPrimos antes
void fact(ll n, map<ll, ll>& f) {  // O (cant primos)
  forall(p, primos) {
    while (!(n % *p)) {
      f[*p]++;  // divisor found
      n /= *p;
    }
  }
  if (n > 1) f[n]++;
}

// Usar asi: divisores(fac, divs, fac.begin()); NO ESTA ORDENADO
void divisores(map<ll, ll>& f, vector<ll>& divs, map<ll, ll>::iterator it,
               ll n = 1) {
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
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll y, k; cin >> y >> k;
    map<ll,ll> f;
    vector<ll> d;
    buscarPrimos();
    fact(y,f);
    divisores(f,d,f.begin());
    sort(all(d));

    if(isPrime(y)){
        if(k < y) cout << k + 1 << '\n';
        else{
            k -= y;
            cout << y + ((k + 1) * y) << '\n';
        }
    }
    else {
        ll pos = 1;
        while(pos < y and k){
            ll val;
            forn(i,size(d)){
                if(d[i] > pos and d[i]%pos == 0){
                    val = d[i] / pos;
                    if(k < val){
                        pos += pos * k;
                        k = 0;
                    }
                    else{
                        pos += pos * (val - 1);
                        k-= val - 1;
                    }
                    break;
                }
                
            }
        }

        cout << pos + (k * y) << '\n';
    }

    return 0;
}