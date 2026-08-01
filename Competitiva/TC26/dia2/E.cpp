
#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x){cout<<#x<<" = "<<x; for(auto e : x) cout<<x<<' ';cout<<endl;}
#define ws <<" "<<
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

void solve(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> v(n, vector<int> (m));
    forn(i,n)forn(j,m) cin>>v[i][j];

    ii rta = {-1,-1,};
    const int M = 1<<m;
    auto f = [&] (ll lvl) -> bool {
        vector<int> idx(M,-1);
        forn(i,n){
            int ma = 0;
            forn(j,m){
                if(v[i][j] >= lvl) ma |= (1ll<<j);
            }
            idx[ma]=i;
        }
        forn(i,M){
            forn(j,M){
                if(idx[i]!=-1 && idx[j]!=-1){
                    if(__builtin_popcount((i|j)) >= m) {
                        rta = {idx[i],idx[j]};
                        return 1;
                    }
                }
            }
        }
        return 0;
    };

    ll lo = -1, hi = 1e9+1;
    while(hi - lo > 1){
        ll m = (hi+lo)/2;
        if(f(m)) lo=m;
        else hi=m;;
    }

    f(lo);

    if(rta == ii{-1,-1}){
        cout<<-1<<endl;
        return;
    }
    cout<<rta.first+1 ws rta.second+1<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    solve();
    return 0;
}