#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' '; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<ii> bid(n);
    map<int, vector<int>> m;
    int a, b;
    forn(i, n) {
        cin >> bid[i].first >> bid[i].second;
        m[bid[i].first].push_back(i);
    }
    
    set<ii> apar;
    for(auto u : m) apar.insert({u.second.back(), u.first});

    int k, q; cin >> q;
    forn(tt, q) {
        cin >> k;
        vector<int> pers(k);
        forn(i, k) {
            cin >> pers[i];
            if(m.count(pers[i])) apar.erase({m[pers[i]].back(), pers[i]});
        }

        if(apar.empty()) { //mate a todos
            cout << 0 << ' ' << 0 << '\n';
        }
        else{
            ii prim = *apar.rbegin();
            apar.erase(--apar.end());
            
            if(apar.empty()) { //quede solo
                cout << bid[m[prim.second][0]].first << ' ' << bid[m[prim.second][0]].second << '\n';
            }
            else {
                ii sec = *apar.rbegin();
                auto ind = upper_bound(all(m[prim.second]), sec.first);
                cout << bid[*ind].first << ' ' << bid[*ind].second << '\n';
            }    

            apar.insert(prim);
        }

        forn(i, k) if(m.count(pers[i])) apar.insert({m[pers[i]].back(), pers[i]});
    }
    
    return 0;
}

// 6
// 1 10
// 2 100
// 3 1000
// 1 10000
// 2 100000
// 3 1000000
// 3
// 1 3
// 2 2 3
// 2 1 2
