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

struct SparseTable{ //nlog(n) tiempo y memoria. Sirve para operaciones idempotentes.
    int N, K;
    vector<vector<int>> st;
    SparseTable(int n) : N(n), K(__lg(n) + 1) {
        st.assign(K, vector<int>(N));
    }
    void build(vector<ii> &v){
        forn(i, N) st[0][i] = v[i].sc;
        forn(i, K - 1) for(int j = 0; j + (1 << (i + 1)) <= N; j++){
            st[i + 1][j] = max(st[i][j], st[i][j + (1 << i)]); 
        }
    }    
    int query(int l, int r) { // [l, r)
        int i = __lg(r - l);
        return max(st[i][l], st[i][r - (1 << i)]);
    };
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<ii> v(n);
        forn(i, n) cin >> v[i].sc >> v[i].fr;
        sort(all(v));
        SparseTable sp(n);
        sp.build(v);
        set<ii> sums;

        ll best = 0;
        


        vector<int> comp(n);

    }



    return 0;
}