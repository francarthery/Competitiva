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
typedef ll tipo;
const int MOD = 1e9 + 7;
struct FenwickTree {
  int N;            // maybe replace vector with unordered_map when "many 0s"
  vector<tipo> ft; 
  FenwickTree(int n) : N(n), ft(n + 1) {}
  void upd(int i0, tipo v) {  // add v to i0th element (0-based)
    for (int i = i0 + 1; i <= N; i += i & -i) ft[i] = (ft[i] + v) % MOD;
  }
  tipo get(int i0) {  // get sum of range [0,i0)
    tipo r = 0;   
    for (int i = i0; i; i -= i & -i) r = (r + ft[i]) % MOD;
    return r;
  }
  tipo get_sum(int i0, int i1) {  // get sum of range [i0,i1) (0-based)
    return get(i1) - get(i0);
  }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> v(n);
    map<int, vector<int>> m;
    forn(i, n) {
        cin >> v[i];
        m[-v[i]].pb(i);
    }
    FenwickTree ft(n);
    
    for(auto i : m){
        vector<ii> upd;
        for(auto j : i.sc) upd.pb({j, ft.get_sum(j, n) + 1});
        for(auto j : upd) ft.upd(j.fr, j.sc);
    }

    cout << ft.get(n) << '\n';

    return 0;
}