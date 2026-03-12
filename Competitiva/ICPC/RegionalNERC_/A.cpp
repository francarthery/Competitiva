#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(stru) (int(stru.size()))
#define all(stru) stru.begin(), stru.end()
#define dbg(x) cout<<#x<<" "<<x<<" ";
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        set<ii> elems, mins;
        forn(i, n) {
            int x; cin >> x;
            elems.insert({i, x});
            mins.insert({x, i});

        }
        int ans = 0;
        while(sz(elems) >= 2){
            ii prim = *elems.begin(), sec = *(++elems.begin());
            if(prim.second == sec.second){
                mins.erase({prim.second, prim.first});
                mins.erase({sec.second, sec.first});
                forn(i, 2){
                    elems.erase(elems.begin());
                }
            }else{
                ii mi = *mins.begin();
                elems.erase({mi.second, mi.first});
                mins.erase(mins.begin());
            }
            ans++;
        }

        cout << ans + sz(elems) << '\n';


    }


    return 0;
}