#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int(x.size()))
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x <<" = "; for(auto e  : x ) cout<<e<< ' ';}cout<<endl;
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

void solve(){
    ll l, r;
    cin>>l>>r;
    if(2*l > r){
        cout<<-1 ws -1;nl;
    } else {
        cout<<l ws 2*l<<endl;
    }
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out","w", stdout);
    #endif

    int t; cin>>t;
    while(t--) solve();

    return 0;
}