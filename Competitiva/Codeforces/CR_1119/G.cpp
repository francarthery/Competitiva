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

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        forn(i, n) cin >> v[i];

        vector<ll> save(n+1), ps(n), ps2(n); 
        forn(i, n-1) save[i+1] = k - (v[i+1] - v[i]);
        forr(i, 1, n) ps[i] = ps[i-1] + save[i];
        forr(i, 1, n) ps2[i] = ps2[i-1] + ps[i];

        vector<ll> ans(n);
        forr(i, 1, n-1) {
            ll pay = v[i+1] - v[i-1] - k;
            if(pay <= 0) continue;
            ans[i] = pay;

            ll l = i+1, r = n;
            while(r-l>1) {
                int m = (r+l)/2;
                if(ps[m] - ps[i+1] < pay) l = m;
                else r = m;
            }

            ans[i] += (pay + ps[i+1]) * (l - (i+1)) - (ps2[l] - ps2[i+1]);
        }

        for(auto i : ans) cout << i << ' ';
        cout << '\n';

    }



    return 0;
}