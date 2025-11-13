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
    /* ios::sync_with_stdio(0);
    cin.tie(0); */
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n;
        vector<vector<int>> g(n);
        vector<int> deg(n);

        forn(i, n - 1){
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
            deg[a]++;
            deg[b]++;
        }

        int rta = 1;

        //vdbg(deg);
        
        forn(i, 2){
            int val = max_element(all(deg)) - deg.begin();

            if(i == 0){
                forn(i, n) {
                    if(deg[i] == deg[val]){
                        int cont = 0;
                        for(int u : g[i]) if(deg[u] == deg[val]) cont++;
                        if(cont <= 1) {
                            val = i; 
                            break;
                        }
                    }
                }
            }

            for(int u : g[val]) deg[u]--;
            rta += deg[val] - 1;
            deg[val] = 0;
        }

        cout << rta << '\n';

    }


    
    return 0;
}