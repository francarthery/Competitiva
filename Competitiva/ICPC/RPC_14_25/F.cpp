#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
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

    string s; cin >> s;
    string c; cin >> c;
    const ll MOD1 = 1e9 + 7;
    const ll MOD2 = 998244353;

    ll nc1 = 0, nc2 = 0, exp = 0;
    dfor(i, sz(c)) nc1 = (nc1 + (c[i] - '0') * expMod(10, exp++, MOD1) % MOD1) % MOD1;
    exp = 0;
    dfor(i, sz(c)) nc2 = (nc2 + (c[i] - '0') * expMod(10, exp++, MOD2) % MOD2) % MOD2;

    function<bool(string&, string&)> f = [&](string &a, string &b) -> bool{
        ll exp = 0, na1 = 0, nb1 = 0, na2 = 0, nb2 = 0;
        dfor(i, sz(a)) na1 = (na1 + (a[i] - '0') * expMod(10, exp++, MOD1) % MOD1) % MOD1;
        exp = 0;
        dfor(i, sz(b)) nb1 = (nb1 + (b[i] - '0') * expMod(10, exp++, MOD1) % MOD1) % MOD1;

        exp = 0;
        dfor(i, sz(a)) na2 = (na2 + (a[i] - '0') * expMod(10, exp++, MOD2) % MOD2) % MOD2;
        exp = 0;
        dfor(i, sz(b)) nb2 = (nb2 + (b[i] - '0') * expMod(10, exp++, MOD2) % MOD2) % MOD2;

        //cout << na1 << ' ' << nb1 << ' ' << na2 << ' ' << nb2 << '\n';
        return (nb1 * nc1 % MOD1 == na1 and nb2 * nc2 % MOD2 == na2);
    };

    forr(i, 1, sz(s)) {
        if(abs(sz(s) - 1 - i + sz(c) - i) > 10) continue; 
        string a = s.substr(0, i);
        string b = s.substr(i);

        if(b[0] == '0') continue;

        if(f(a, b)){
            cout << a << ' ' << b << '\n';
            return 0;
        }
    }

    
    return 0;
}