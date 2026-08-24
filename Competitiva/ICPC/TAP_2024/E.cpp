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

    ll n, p; cin >> n >> p;
    vector<ll> dp(p+1, 0);

    vector<array<int, 3>> v(n);
    forn(i, n) cin >> v[i][0] >> v[i][1] >> v[i][2];

    // sort(all(v), [&](auto &a, auto &b) {
        
    // });

    forn(i, n) {
        forr(j, 1, p+1) {
            int nj = (j - v[i][1]) / v[i][0];
            if(nj >= 0 and j - v[i][1] >= 0) dp[nj] = max(dp[nj], dp[j] + v[i][2]);
        }
        // vdbg(dp);
    }

    cout << *max_element(all(dp)) << '\n';


    return 0;
}

/*
Posibilidades sort:
por a y despues b: el a mas chico tiene 100000 en B y me destruyen.
por b y despues a: el b mas chico tiene 100000 en A y me destruyen.
por (p-b)/a: capaz el que mas me destruye tiene 100000 en C y los otros 200, 1.

4 100
1 100000 10
100000 1 10
2 2 100
2 100 100000

Orden optimo:
2 100 100000
...

*/