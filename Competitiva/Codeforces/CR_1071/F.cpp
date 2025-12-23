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
    // #ifdef fran
    //     freopen("input.in", "r", stdin);
    //     freopen("output.out", "w", stdout);
    // #endif

    string modo; cin >> modo;
    int t; cin >> t;
    while(t--){
        if(modo == "first"){
            int n, m; cin >> n >> m;
            vector<vector<int>> g(n);
            forn(i, m){
                int a, b; cin >> a >> b; a--; b--;
                g[a].pb(b);
                g[b].pb(a);
            }

            vector<int> vis(n);
            vis[0] = 1;
            queue<int> q;
            q.push(0);

            while(sz(q)){
                int s = q.front();
                q.pop();
                
                for(int u : g[s]){
                    if(!vis[u]){
                        vis[u] = vis[s] + 1;
                        q.push(u);
                    }
                }
            }

            for(int i : vis){
                if(i % 3 == 0) cout << 'r';
                else if(i % 3 == 1) cout << 'g';
                else cout << 'b';
            }
            cout << endl;

            continue;
        }

        int q; cin >> q;
        forn(i, q){
            int dg; cin >> dg;
            string nodos; cin >> nodos;

            int r = -1, g = -1, b = -1;
            forn(i, sz(nodos)) {
                if(nodos[i] == 'r') r = i + 1;
                else if(nodos[i] == 'g') g = i + 1;
                else b = i + 1;                
            }

            if(r != -1 and b != -1) cout << r << endl;
            else if(b != -1 and g != -1) cout << b << endl;
            else if(r != -1 and g != -1) cout << g << endl;
            else if(r != -1) cout << r << endl;
            else if(g != -1) cout << g << endl;
            else if(b != -1) cout << b << endl; 
        }


    }



    return 0;
}
