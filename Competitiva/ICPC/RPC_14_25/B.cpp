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
    vector<vector<ll>> v(n, vector<ll>(3));
    forn(i, n) forn(j, 3) cin >> v[i][j];

    forn(i, n) sort(all(v[i]));

    ll x = 1e9, y = 1e9, z = 1e9;
    forn(i, n) x = min(x, v[i][0]);
    forn(i, n) y = min(y, v[i][1]);
    forn(i, n) z = min(z, v[i][2]);

    cout << x * y * z << '\n';


    return 0;
}