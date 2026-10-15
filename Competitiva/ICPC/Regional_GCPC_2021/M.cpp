#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end();
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "<<;for(auto e : x) cout<<e<<" ";cout<<endl;}

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef long double ld;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("in2","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    ll n,s,e;
    cin>>n>>s>>e;
    long double rta = (long double) s / (n-e);

    cout<<fixed<<setprecision(15)<<rta<<'\n';

    return 0;
}