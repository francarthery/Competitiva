#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=(a); i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<< "\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct P{
    ll x,y;
};
const ll inf = 2e18;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out","w", stdout);
    #endif

    int n; cin>>n;
    vector<ll> D(n);
    vector<P> pt(n);
    forn(i,n){
        cin>>pt[i].x>>pt[i].y;
    }   

    forr(i,1,n){
        D[i] = abs(pt[i].x - pt[i-1].x) + abs(pt[i].y - pt[i-1].y);
    }

    ll K = 0;
    ll sig = -1;
    ll lo = 0, hi = D[1];
    forr(i,1,n){
        K = D[i] - K;
        if(sig == -1)
            hi = min(hi,K);
        else   
            lo = max(lo, -K);
        // dbg(lo);
        // dbg(K);
        sig = -sig;
    }
    // dbg(lo);
    // dbg(hi);
    if(!(lo+1 < hi)){
        cout<<-1;nl;
        return 0;
    }

    cout<<hi-1;nl;




}