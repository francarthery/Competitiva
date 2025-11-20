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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ll sum = 0;
        vector<ll> v(n);
        forn(i, n) cin >> v[i];

        if(n < 3){
            cout << -1 << '\n';
            continue;
        }

        forn(i, n) sum += v[i];
        sort(all(v));

        ll med = n / 2;
        ll x = 2LL * v[med] * n - sum;
        cout << max(x + 1, 0LL) << '\n';
    }

    
    return 0;
}