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

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n));
    vector<ii> v;
    forn(i, m){
        cin >> a >> b; a--; b--;
        g[a][b] = g[b][a] = 1;
    }

    if(n == 1) cout << "NO\n";
    else{
        forn(i, n / 2){
            forn(j, n / 2){
                if(i != j and g[i][j] == 0) v.pb({i + 1, j + 1}), g[i][j] = g[j][i] = true;
            }
        }

        forr(i, n / 2, n){
            forr(j, n / 2, n){
                if(i != j and g[i][j] == 0) v.pb({i + 1, j + 1}), g[i][j] = g[j][i] = true;
            }
        }

        cout << "YES\n";
        cout << sz(v) << '\n';
        for(ii &i : v) cout << i.fr << ' ' << i.sc << '\n';
    }
    
    return 0;
}