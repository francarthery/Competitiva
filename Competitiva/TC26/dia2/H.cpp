#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) (x.begin(), x.end())
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x){cout<<#x<<" = "<<x; for(auto e : x) cout<<x<<' ';cout<<endl;}
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ii> inter(n);
        map<int, vector<ii>> ev;
        set<ii> abiertos;

        int a, b;
        vector<int> ans(n);
        forn(i, n) {
            cin >> inter[i].first >> inter[i].second;
            a = inter[i].first, b = inter[i].second;
            ev[a].push_back({0, i}); //abre
            ev[b].push_back({1, i});
        }

        int contev = 0, conj = 1;
        for(auto x : ev) {
            for(auto i : x.second) {
                contev++;
                if(i.first == 0) {
                    abiertos.insert({x.first, i.second});
                    ans[i.second] = conj;
                }
                else {
                    abiertos.erase({inter[i.second].first, i.second});
                }
            }
            if(sz(abiertos) == 0 and contev < 2*n and conj == 1) conj++; 
        }

        if(conj == 1) cout << -1;
        else for(int i : ans) cout << i << ' ';
        cout << '\n';
    }


    return 0;
}