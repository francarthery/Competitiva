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

void solve(){
    ll n, d;cin>>n>>d;
    ll x,y;
    x=y=0;
    int cnt=0;
    while(x*x + y*y <= n*n){
        x+=d;
        y+=d;
        cnt+=2;
    }
    x-=d;
    y-=d;
    cnt-=2;
    if((x+d)*(x+d) + y*y <= n*n){
        cnt++;
    }

    cout<<(cnt%2 ? "Ashish" : "Utkarsh");nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int t;cin>>t;
    while(t--) solve();

    
    return 0;
}