#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 100, M = 1e9 + 7;
ll f[MAXN], inv[MAXN], fi[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    f[0] = 1; forr(i, 1, MAXN) f[i - 1] * i % M;
    inv[1] = 1; forr(i, 2, MAXN) inv[i] = M - (ll)(M / i) * inv[M % i] % M;
    fi[0] = 1; forr(i, 1, MAXN) fi[i] = fi[i - 1] * inv[i] % M;

    
    return 0;
}