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
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> v(n, vector<ll>(m));
        forn(i, n) forn(j, m) cin >> v[i][j];

        forn(i, n) forn(j, m){
            ll ma = 0;
            if(((i == 0 or v[i - 1][j] < v[i][j]) and (i == n - 1 or v[i + 1][j] < v[i][j]) and (j == 0 or v[i][j - 1] < v[i][j]) and (j == m - 1 or v[i][j + 1] < v[i][j]))){
                if(i > 0) ma = max(ma, v[i - 1][j]);
                if(i < n - 1) ma = max(ma, v[i + 1][j]);
                if(j > 0) ma = max(ma, v[i][j - 1]);
                if(j < m - 1) ma = max(ma, v[i][j + 1]);
                v[i][j] = ma;
            }
        }

        forn(i, n) {
            forn(j, m){ 
                cout << v[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    
    return 0;
}