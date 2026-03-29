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

    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>g(n);
        vector<int> gra(n), sal(n), din(n), vst(n), salida;
        priority_queue<tuple<int,int,int>> q;

        forn(i,m){
            int u,v;cin>>u>>v;
            u--,v--;
            g[u].push_back(v);
            gra[v]++;
            sal[u]++;
        }

        forn(i,n) q.push({sal[i]-gra[i], -gra[i], i});

        int perdi=0;

        while(q.size()){
            auto [neto, _gra, u] = q.top();
            q.pop();
            if(vst[u])continue;
            vst[u]=1;
            salida.push_back(u);
            perdi+=(-_gra);

            for(int v: g[u]){
                if(!vst[v]){
                    ++din[v];
                    int dif = -(gra[v]-din[v]);
                    q.push({sal[v]+dif, dif, v});
                }
            }
        }

        int gane = m-perdi;
        if(sz(salida) != n || !(gane>=(m+1)/2)){
            cout<<-1<<endl;
            continue;
        }

        forn(i,n) cout<<salida[i]+1<<' ';
        cout<<endl;

        
    }



    return 0;
}