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

    int t;
    cin >> t;
    while(t--){
        ll n, x, y, aux;
        cin >> n >> x >> y;
        vector<ll> v(n), v2(n);
        forn(i, n) cin >> v[i];
        ll sum = accumulate(all(v), 0ll);
        forn(i, n) v2[i] = sum - v[i];
        sort(rall(v));
        sort(all(v2));

        ll cont = 0;
        forn(i, n){
            int l = lower_bound(v2.begin() + i + 1, v2.end(), x + v[i]) - v2.begin();
            int r = upper_bound(v2.begin() + i + 1, v2.end(), y + v[i]) - v2.begin();

            cont += r - l;
        }

        cout << cont << '\n';
    }

    return 0;
}