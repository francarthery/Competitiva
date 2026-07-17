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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n; cin >> n;
    vector<ll> v(n);
    forn(i, n) cin >> v[i];

    bool ok = false;
    forn(i, n-1) {
        string prim = to_string(v[i]);
        string sec = to_string(v[i+1]);
        prim[0] = '9';
        if(stoll(prim) > stoll(sec)) {
            v[i] = stoll(prim);
            ok = true;
            break;
        }
        prim = to_string(v[i]);
        
        sec[0] = '1';
        if(sz(sec) == 1) sec[0] = '0';
        if(stoll(prim) > stoll(sec)){
            v[i+1] = stoll(sec);
            ok = true;
            break;
        }
        sec = to_string(v[i+1]);
    }

    if(ok) for(auto i : v) cout << i << ' ';
    else cout << "impossible";
    cout << '\n';


    return 0;
}