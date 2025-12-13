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
typedef pair<ll, ll> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    //perdon
    int b, n; cin >> b >> n;
    vector<int> c(n), w(n);
    vector<array<string, 3>> v(n);
    map<string, int> m2;
    int dist = 0;
    
    forn(i, n){
        auto &[x, y, z] = v[i];
        cin >> x >> y >> z >> c[i] >> w[i];
        w[i] = -w[i];
        if(!m2.count(x)) m2[x] = dist++;
    }

    vector<ii> best(dist, ii(1e9, 1e9));
    vector<int> frec(dist), gr(n);
    vector<array<int, 3>> v2(n);
    vector<vector<int>> g(n);
    queue<int> q;

    forn(i, n) {
        v2[i][0] = m2[v[i][0]];
        if(m2.count(v[i][1])){
            v2[i][1] = m2[v[i][1]];
            g[v2[i][1]].pb(i), gr[i]++;
        }
        else v2[i][1] = -1;
        if(m2.count(v[i][2])){
            v2[i][2] = m2[v[i][2]];
            g[v2[i][2]].pb(i), gr[i]++;
        }
        else v2[i][2] = -1;
        
        if(!gr[i]) q.push(i);

        frec[v2[i][0]]++;
    }

    while(sz(q)){
        int s = q.front();
        q.pop();

        ii y, z;
        if(v2[s][1] != -1) y = best[v2[s][1]];
        if(v2[s][2] != -1) z = best[v2[s][2]];
        best[v2[s][0]] = min(best[v2[s][0]], {y.fr + z.fr + c[s], y.sc + z.sc + w[s]});
        frec[v2[s][0]]--;
        
        if(!frec[v2[s][0]]) for(int u : g[v2[s][0]]){
            gr[u]--;
            if(!gr[u]) q.push(u);
        }
    }

    vector<ll> dp(b + 1);
    forn(i, sz(best)){
        dfor(j, b + 1 - best[i].fr){
            dp[j + best[i].fr] = max(dp[j + best[i].fr], dp[j] - best[i].sc);
        }
    }
    
    int tarasca = b;
    dfor(i, b) if(dp[i] == dp[b]) tarasca = i;

    cout << dp[b] << '\n' << tarasca << '\n';


    return 0;
}