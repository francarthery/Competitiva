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
        //freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    ll n, k, x, a, b, c; cin >> n >> k >> x >> a >> b >> c;
    ll ans = 0;

    deque<ii> q;
    forn(i, n){
        if(i) x = (a * x + b) % c;
        while(sz(q) and q.back().fr >= x) q.pop_back();
        if(sz(q) and q.front().sc <= i - k) q.pop_front();
        q.push_back({x, i});
        if(i >= k - 1) ans ^= q.front().fr;
    }
    
    cout << ans << '\n';

    return 0;
}