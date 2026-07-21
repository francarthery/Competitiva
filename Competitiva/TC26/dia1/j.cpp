#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend9)()
#define dbg(x) cout<<#x <<" = " << x << endl;
#define vdbg(x) {cout<<#x<<" = ["; for(auto e : x) cout<<e<<' '; cout<<"\n";}
#define nl cout<<"\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

// struct UnionFind{
//     int nsets;
//     vector<int> f, setsz;
//     vector<ii> rep;
//     UnionFind(int n) : nsets(n), f(n, -1), setsz(n, -1), rep(n) {}
//     int comp(int x) {return (f[x] == -1 ? x : f[x] == comp(f[x]));}
//     bool join(int i, int j) {
//         int a = comp(i), b = comp(j);
//         if(a != b) {
//             if(setsz[a] > setsz[b]) swap(a, b);
//             f[a] = b;
//             nsets--; setsz[b] += setsz[a];
//         }
//         return a == b;
//     }
// };

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int a, b, n; cin >> n;
    vector<ii> ext(n+1), comps;
    forn(i, n) {
        cin >> a >> b;
        ext[i+1] = {a, b};
    }

    vector<bool> vis(n + 1);
    forn(i, n) if(!vis[i+1]) {
        int prim = i+1, sec = i+1;

        vis[prim] = true;
        
        while(ext[prim].first != 0) {
            prim = ext[prim].first;
            vis[prim] = true;
        }
        while(ext[sec].second != 0) {
            sec = ext[sec].second;
            vis[sec] = true;
        }

        comps.push_back({prim, sec});
    }

    // for(auto i : comps) cout << i.first << ' ' << i.second << '\n';
    // cout << "pepeeee\n";

    forn(i, sz(comps) - 1) {
        ext[comps[i].second].second = comps[i+1].first;
        ext[comps[i+1].first].first = comps[i].second;
    }

    forr(i, 1, n+1) cout << ext[i].first << ' ' << ext[i].second << '\n';
    
    return 0;
}