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

ll expMod(ll b, ll e, ll m = 1e9 + 7) {  // O(log e)
    if (e < 0) return 0;
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
        b = b * b % m;                 // b = mulMod(b,b,m);
        e >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        ll n, a, b; cin >> n;
        vector<vector<int>> g(n + 1);
        forn(i, n - 1){
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        g[0].pb(1);
        g[1].pb(0);

        ll b1 = -1, b2 = -1; // puedo separar 2 veces
        bool separe = false, flag = true;
        function<void(int, int, int)> dfs = [&](int s, int fa, int brazo){
            if(!flag) return;
            if(brazo == 0) b1++;
            else if(brazo == 1) b2++;

            if(separe and sz(g[s]) > 2 or sz(g[s]) > 3) {
                flag = false;
                return;
            }
            if(sz(g[s]) == 3) {
                separe = true;
                for(int &u : g[s]){
                    if(u == fa) continue;
                    if(b1 == -1){
                        b1 = 0;
                        dfs(u, s, 0);
                    }
                    else{
                        b2 = 0;
                        dfs(u, s, 1);
                    }
                }
            }

            for(int &u : g[s]){
                if(u == fa) continue;
                dfs(u, s, brazo);
            }
        };

        dfs(0, -1, -1);
        //dbg(b1); dbg(b2);
        if(!flag) cout << 0 << '\n';
        else if(b1 == b2 and b1 == -1) cout << expMod(2, n) << '\n';
        else if(b1 == b2) cout << (2 * expMod(2, (n - b1 - b2))) % (int)(1e9 + 7) << '\n';
        else cout << (3 * expMod(2, (n - b1 - b2 + 1))) % (int)(1e9 + 7) << '\n';

    }



    return 0;
}