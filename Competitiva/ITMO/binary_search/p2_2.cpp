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
typedef long double ld;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    ll sum = accumulate(all(v), 0ll);
    ll lim = log2l(sum / 1e-6) + 30; //hacer iteraciones hasta como minimo log(maxans / eps)

    ld l = 0, r = sum;
    forn(t, lim){
        ld m = (r + l) / 2.0;
        ll ans = 0;
        forn(i, n) ans += v[i] / m;
        if(ans >= k) l = m;
        else r = m;
    }
    
    cout << fixed << setprecision(6) << l << '\n';

    return 0;
}