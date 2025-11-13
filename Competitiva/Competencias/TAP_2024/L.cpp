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

    int n, q, l, r;
    cin >> n >> q;
    vector<ll> v(n), a(n + 1), b(n + 1), u(n + 1);
    forn(i, n) cin >> v[i];
    forn(i, n){
        a[i + 1] = a[i];
        b[i + 1] = b[i];
        u[i + 1] = u[i];
        if(v[i] == 1) u[i + 1]++;
        else if((v[i] & (v[i] - 1)) == 0) a[i + 1] += v[i];
        else if(v[i] & 1) b[i + 1] += v[i];
    }

    forn(i, q){
        cin >> l >> r;
        ll unos = u[r] - u[l - 1];
        ll brimix = b[r] - b[l - 1];
        ll agus = a[r] - a[l - 1] + (unos & 1);
        if(agus == brimix) cout << "E\n";
        else if(agus > brimix) cout << "A\n";
        else cout << "B\n";
    }

    
    return 0;
}