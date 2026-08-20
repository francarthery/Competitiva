#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(int)(a);i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=0;i>=0;i--)
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define nl cout<<"\n";
#define ws <<" "<<
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

ll b, l, res;
ll mod;
ll binexp(ll b, ll e, ll m){
    ll ret = 1;
    while(e){
        if(e&1) ret = b*ret%m;
        b = b*b%m;
        e>>=1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.in","r", stdin);
    freopen("output.out","w", stdout);
    #endif
    cin>>b>>l;
    mod=b+1;
    vector<ll> v(l);
    forn(i,l) cin>>v[i];
    reverse(all(v));
    ll pot = 0;
    forn(i,l){
        res = (res + v[i]*binexp(b, pot++, mod)%mod) % mod;
    }
    
    if(res==0){
        cout<<0 ws 0;nl;
        return 0;
    }
    

    int rtapos=-1, rtadig=-1;
    ll inv = binexp(b,mod-2,mod);
    forr(p,0,l){
        // dbg(res);
        if(res <= v[p]){
            rtapos = l-p;
            rtadig = v[p]-res;
        }
        ll nue = res*b%mod;
        res=nue;
    }

    
    cout<<rtapos ws rtadig;nl;



    return 0;
}