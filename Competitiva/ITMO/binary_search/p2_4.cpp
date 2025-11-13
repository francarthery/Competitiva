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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<ll, ll, ll> iii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, g;
    cin >> g >> n;
    vector<iii> v(n);
    for(auto &[a, b, c] : v) cin >> a >> b >> c;

    ll l = -1, r = 1e9;
    while(r - l > 1){
        ll m = (r + l) / 2;
        ll cont = 0;
        forn(i, n){
            auto &[t, z, y] = v[i];
            cont += (m / (t * z + y)) * z + min(z, (m % (t * z + y)) / t);
        }
        if(cont >= g) r = m;
        else l = m;
    }

    cout << r << '\n';
    ll infle = 0;
    forn(i, n){
        auto &[t, z, y] = v[i];
        ll puedo = (r / (t * z + y)) * z + min(z, (r % (t * z + y)) / t);
        ll ans = min(puedo, g - infle);
        cout << ans << ' ';
        infle += ans;
    }

    cout << '\n';
    
    return 0;
}