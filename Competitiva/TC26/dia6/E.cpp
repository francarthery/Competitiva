#include <bits/stdc++.h>
#define forr(i,a,b) for(ll i=a; i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(x) (int(x.size()))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r", stdin);
    freopen("out","w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        sort(all(v));

        ll ans = 0;
        forn(i, n) {
            ll ind = upper_bound(all(v), v[i] + 2) - v.begin() - 1;
            if(ind > i) {
                ll tam = ind - i;
                ans += (tam * (tam-1)) / 2;
            }
        }

        cout << ans << '\n';
    }


    return 0;
}