#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int) (x).size())
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto e : x) cout<<e<<" ";cout<<endl;}
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        int n, so, p; cin >> n >> so >> p;
        vector<int> v(so);
        forn(i, so) cin >> v[i]; //y esto?

        ll s = min(so, p);
        ll u = p - s;
        ll ss = so - s;
        ll su = n - s - 1 - u;

        ll ans = 0;

        if(su) ans += 2ll * su * (su-1);
        ans += 8ll * su * u;
        if(s) ans += 2ll * (su + 3ll * su * (s-1));
        ans += 4ll * ss * su;
        if(u) ans += 4ll * u * (u-1);
        ans += 6ll * u * s;
        ans += 8ll * u * ss;
        if(s) ans += 2ll * s * (s-1);
        if(s) ans += 2ll * (ss * 3ll * (s-1) * ss);
        if(ss) ans += 2ll * ss * (ss-1);
        ans += 4ll * su;
        ans += 4ll * u;
        ans += 2ll * s;
        ans += 4ll * ss;

        cout << ans << '\n';


    }


}