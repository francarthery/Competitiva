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

    int n;cin>>n;
    vector<ll> a(n), b(n);
    
    map<ii,ll> f, b0;
    ll mx = 0, cntz = 0, d0 = 0;

    forn(i,n) cin>>a[i];
    forn(i,n) cin>>b[i];

    forn(i,n){
        if(a[i] == 0){
            if(b[i] == 0)
                d0++;
            continue;
        }
        if(b[i] == 0){
            cntz++;
            continue;
        }
        ll d = gcd(abs(a[i]), abs(b[i]));
        ii x = {-abs(b[i]/d) * (b[i] * a[i] < 0 ? 1 : -1), abs(a[i]/d)};
        mx = max(mx, ++f[x]);
    }
    
    cout<<max(mx+d0, cntz+d0)<<endl;
    
    return 0;
}