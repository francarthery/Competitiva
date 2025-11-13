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

    const int MAXN = 2e5 + 1;
    int t; cin >> t;
    while(t--){
        ll n, y; cin >> n >> y;
        vector<ll> v(n), cant(MAXN), frec(MAXN);
        forn(i, n) {
            cin >> v[i];
            frec[v[i]]++;
        }
        sort(all(v));

        forr(i, 1, MAXN) cant[i] = cant[i - 1] + frec[i];    

        ll best = -1e18;
        forr(x, 2, MAXN){
            ll ans = -y*n;
            for(int k = 0; k*x + 1 < MAXN; k++){
                ll l = k*x + 1, r = min(MAXN - 1, (k + 1)*x);
                ll c = cant[r] - cant[l - 1];
                
                ans += y * min(frec[(k + 1)], c); //tags que me ahorro
                ans += c * (k + 1); //ganancia final items
            }

            best = max(best, ans);
        }

        cout << best << '\n';
    }



    return 0;
}