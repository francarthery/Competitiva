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

    int n, x; cin >> n; 
    vector<vector<int>> g(n);
    vector<int> w(n), lis, rta(n);

    forn(i, n - 1){
        cin >> x;
        g[x - 1].pb(i + 1);
    }

    forn(i, n) cin >> w[i];

    function<void(int)> dfs = [&](int s){
        int pos = lower_bound(all(lis), w[s]) - lis.begin();
        int ant = -1;
        if(pos == sz(lis)) lis.pb(w[s]); //es mayor que el mayor de los elementos de la lis
        else {
            ant = lis[pos];
            lis[pos] = w[s];
        }

        rta[s] = sz(lis);

        for(int &u : g[s]) dfs(u);

        if(ant == -1) lis.pop_back();
        else lis[pos] = ant;
    };

    dfs(0);

    forr(i, 1, n) cout << rta[i] << ' ';
    cout << '\n';

    return 0;
}