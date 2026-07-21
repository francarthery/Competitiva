#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define dbg(x) cout<<#x <<" = " << x << endl;
#define vdbg(x) {cout<<#x<<" = ["; for(auto e : x) cout<<e<<' '; cout<<"\n";}
#define nl cout<<"\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> v(n);
        forn(i, n) {
            int k; cin >> k;
            v[i].resize(k);
            forn(j, k) {
                cin >> v[i][j];
                v[i][j]--;
            }
            sort(rall(v[i]));
        }

        vector<bool> use(n);
        vector<int> match(n);
        int cont = 0, prim = -1;
        forn(i, n) {
            while(sz(v[i]) and use[v[i].back()]) v[i].pop_back();
            if(sz(v[i])) {
                match[i] = v[i].back();
                use[v[i].back()] = true;
                cont++;
            }
            else prim = i;
        }

        cout << (cont == n ? "OPTIMAL" : "IMPROVE") << '\n';
        if(cont != n) {
            int sec;
            forn(i, n) if(!use[i]) {
                sec = i;
                break;
            } 
            cout << prim + 1 << ' ' << sec+1 << '\n';
        }
    }

    
    return 0;
}