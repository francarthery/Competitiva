#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int n, neutro = 0; //Elegir neutro operacion. N YA ESTA DECLARADO
vector<int> t; //Asignar tam = 2 * n, neutro

void build() {  // build the tree. O(n)
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int que(int l, int r) { // Range [l, r) 
  int res = neutro;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int m, q;
    cin >> n >> m >> q;
    t.assign(2 * n, neutro);
    vector<int> v(n), cap(n);
    vector<ii> days(m), res(q);
    vector<tuple<int, int, int, int>> query(q);
    forn(i, n) cin >> v[i];
    for(auto &[a, b] : days) cin >> a >> b;
    forn(i, q){
        auto &[a, b, c, d] = query[i];
        cin >> a >> b >> c;
        d = i; //Guardo el indice de la query
    }
    sort(all(query));

    int cont = 0;
    forn(i, q){
        while(get<0>(query[i]) > cont){
            auto &[a, b] = days[cont];
            cap[a - 1] += b;
            cap[a - 1] = min(cap[a - 1], v[a - 1]);
            modify(a - 1, cap[a - 1]);
            cont++;
        }
        res[i] = {get<3>(query[i]), que(get<1>(query[i]) - 1, get<2>(query[i]))};
    }
    sort(all(res));
    for(ii &i : res) cout << i.sc << '\n';
    
    return 0;
}