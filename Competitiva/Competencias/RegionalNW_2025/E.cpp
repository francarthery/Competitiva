#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(ll i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;


template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

ll expMod(ll b, ll e, ll m) {  // O(log e)
    if (e < 0) return 0;
    ll ret = 1;
    while (e) {
      if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
      b = b * b % m;                 // b = mulMod(b,b,m);
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

    ll n, k; cin >> n >> k;
    string s; cin >> s;

    forn(i, n) cout << s[((ll)i * expMod(2, k, n)) % n];
    cout << '\n';

    
    return 0;
}
