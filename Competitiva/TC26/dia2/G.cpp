#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ws <<" "<<
#define vdbg(x){cout<<#x<<" = "<<x; for(auto e : x) cout<<x<<' ';cout<<endl;}
using namespace std;
#define nl cout<<"\n";

typedef long long ll;
typedef pair<int,int> ii;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, 
tree_order_statistics_node_update> iset;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
    vector<ii> ma(n+1);
    vector<int> rtamn(n), rtamx(n);
    iota(all(rtamn),1);
    iota(all(rtamx),1);
    iset s;
    forr(i,1,n+1){
        ma[i] = {i,i};
        s.insert({i,i});
    }

    forn(i,m){
        int x;cin>>x;
        rtamn[x-1] = 1;
        ii bus = ma[x];
        int ind = s.order_of_key(bus);
        rtamx[x-1] = max(rtamx[x-1],ind+1);
        int primi = s.begin()->first;
        s.erase(bus);
        ma[x] = {primi-1, x};
        s.insert(ma[x]);
    }
    forr(x,1,n+1){
        auto bus = ma[x];
        int ind = s.order_of_key(bus);
        rtamx[x-1] = max(rtamx[x-1],ind+1);
    }

    forn(i,n){
        cout<<rtamn[i] ws rtamx[i];nl;
    }

    return 0;
}