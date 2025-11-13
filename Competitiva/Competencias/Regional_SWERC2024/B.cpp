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
#define sqr(x) ((x)*(x))

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    k = min(k, n);
    vector<ii> v(n);
    vector<vector<ll>> dists(n, vector<ll>(n));
    vector<vector<ii>> dp(k, vector<ii>(n, ii(1e18, -1))); // dp[i][j] = {costo cubrir rango [j, n) con i dias, donde puse el ultimo k}
    forn(i, n) {
        cin >> v[i].fr;
        v[i].sc = i;
    }
    sort(all(v));

    forr(i, 1, n){
        dfor(j, i){
            dists[i][j] = dists[i][j + 1] + sqr(v[j].fr - v[i].fr);
        }
    }

    forn(i, n) dp[0][i] = {dists[n - 1][i], n - 1};

    forr(i, 1, k){
        forn(j, n - i){
            forr(l, j, n - i){
                if(dp[i][j].fr >= dp[i - 1][l + 1].fr + dists[l][j]){
                    dp[i][j] = {dp[i - 1][l + 1].fr + dists[l][j], l};
                }
            }
        }
    }

    // forn(i, k) {
    //     forn(j, n) cout << dp[i][j].fr << ' ';
    //     cout << '\n';
    // }

    vector<int> points;
    int pos = 0;
    dfor(i, k){
        points.pb(dp[i][pos].sc);
        pos = points.back() + 1;
    }
    reverse(all(points));

    forn(i, n){
        while(points.back() < i) points.pop_back();
        v[i].fr = v[points.back()].fr;
    }

    sort(all(v), [&](ii&a, ii&b) {return a.sc < b.sc;});
    for(auto i : v) cout << i.fr << ' ';
    cout << '\n';


    return 0;
}