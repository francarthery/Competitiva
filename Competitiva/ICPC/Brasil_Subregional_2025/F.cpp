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

const ll mod = 1e9+7;
ll binexp(ll b, ll e){
    ll ret = 1;
    while(e){
        if(e&1) ret = ret * b % mod;
        e>>=1;
        b = b*b%mod;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out","w", stdout);
    #endif

    int n,q;
    cin>>n>>q;
    vector<ll> rta(n+1);
    
    vector<ll> com(q);
    vector<ll> clc;
    forn(i,q) {
        cin>>com[i];
    }
    clc = com;
    ll medio = binexp(2,mod-2);

    ll dis = medio;
    forn(i,q){
        com[i] = (com[i] * dis) % mod;
        dis = (dis * medio) % mod;
    }

    vector<ll> suf(q+1);
    dfor(i,q){
        suf[i] = (suf[i+1] + com[i]) % mod;
    }

    int mesa = 1;
    ll p2 = 1;
    forn(i,q){
        ll mul = (i==0?1:medio);
        ll sum = (suf[i] * p2 % mod) * mul % mod;
        rta[mesa] = (rta[mesa] + sum) % mod;
        mesa = clc[i];
        p2 = (p2 * 2ll) % mod;
    }

    forr(i,1,n+1) {
        cout<<rta[i]%mod;nl;
    }

}