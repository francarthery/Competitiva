#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;


typedef ll Elem;
typedef ll Alt;
const Elem neutro = 1e9;
const Alt neutro2 = 0;
Elem oper(const Elem& a, const Elem& b) { return min(a, b); }
struct ST {
  int sz;
  vector<Elem> t;
  vector<Alt> dirty;  // Alt and Elem could be different types
  ST(int n) {
    sz = 1 << (32 - __builtin_clz(n));
    t = vector<Elem>(2 * sz, neutro);
    dirty = vector<Alt>(2 * sz, neutro2);
  }
  Elem& operator[](int p) { return t[sz + p]; }
  void updall() { dfor(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]); }
  void push(int n, int a, int b) {  // push dirt to n's child nodes
    if (dirty[n] != neutro2) {      // n = node of range [a,b)
      t[n] += dirty[n];   // CHANGE for your problem
      if (n < sz) {
        dirty[2 * n] = min(dirty[2 * n], dirty[n]);      // CHANGE for your problem
        dirty[2 * n + 1] = max(dirty[n], dirty[2 * n + 1]);  // CHANGE for your problem
      }
      dirty[n] = neutro2;
    }
  }
  Elem get(int i, int j, int n, int a, int b) {  // O(lgn)
    if (j <= a || b <= i) return neutro;
    push(n, a, b);                      // adjust value before using it
    if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
    int c = (a + b) / 2;
    return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
  }
  Elem get(int i, int j) { return get(i, j, 1, 0, sz); }
  // altera los valores en [i, j) con una alteracion de val
  void update(Alt val, int i, int j, int n, int a, int b) {  // O(lgn)
    push(n, a, b);
    if (j <= a || b <= i) return;
    if (i <= a && b <= j) {
      dirty[n] += val;  // CHANGE for your problem
      push(n, a, b);
      return;
    }
    int c = (a + b) / 2;
    update(val, i, j, 2 * n, a, c), update(val, i, j, 2 * n + 1, c, b);
    t[n] = oper(t[2 * n], t[2 * n + 1]);
  }
  void update(Alt val, int i, int j) { update(val, i, j, 1, 0, sz); }
};  // Use: definir operacion, neutros, Alt, Elem, uso de dirty
// cin >> n; ST st(n); forn(i,n) cin >> st[i]; st.updall()


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int q; cin >> q;
    vector<ii> op, ord;
    char c; int x;
    forn(i, q){
        cin >> c >> x;
        op.push_back({{c == '+' ? 1 : 0}, x});
        if(c == '+') ord.pb({x, i});
    }
    int n = sz(ord);
    vector<int> idx;
    forn(i, n) idx[ord[i].sc] = i;

    sort(all(ord));
    ST st(n);
    indexed_set s;

    forn(i, q){
        auto [oper, val] = op[i];
        if(oper){
            s.insert({op[i].sc, idx[i]});
            int elem = op[i].sc + sz(s) - s.order_of_key({op[i].sc, idx[i]}) - 1;
            st.update(-1e9 + elem, idx[i], idx[i] + 1);
            st.update(1, 0, idx[i]);
        }
        else{
            
        }
        cout << st.get(0, n);
    }



    



    return 0;
}