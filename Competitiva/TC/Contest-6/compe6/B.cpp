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

const int K = 20; //log2(cant_elementos) + 1
const int MAXN = 1e5 + 100;
vector<vector<int>> st(K, vector<int>(MAXN));

void sparse(vector<int> &v){ //Llamar a sparse antes para precomputar la tabla O(nlogn)
    st[0] = v;

    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= v.size(); j++)
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); //Construccion de abajo para arriba
}

int query(int l, int r){ //O(1)
    int i = (int)log2(r - l + 1);
    return min(st[i][l], st[i][r - (1 << i) + 1]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n, c, sum = 0;
    cin >> n >> c;
    vector<int> v(n), mi(n);
    vector<ll> dp(n);
    forn(i, n){
        cin >> v[i];
        sum += v[i];
    }

    if(c <= n){
        sparse(v);
        forr(i, c - 1, n) mi[i] = query(i - c + 1, i);
        dp[c - 1] = mi[c - 1];
        forr(i, c, n) dp[i] = max(dp[i - 1], mi[i] + dp[i - c]);
    }

    cout << sum - dp[n - 1] << '\n';
    
    return 0;
}