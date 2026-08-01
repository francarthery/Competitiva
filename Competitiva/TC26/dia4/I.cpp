#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<< " = " <<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
#define on(mask, i) (mask & (1<<i))
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r", stdin);
    freopen("out","w",stdout);
    #endif
    
    ll n;
    cin>>n;
    vector<ll> cnt1(32);
    vector<vector<ll>> cnt2(32, vector<ll>(32));
    ll cnt3[32][32][32];
    memset(cnt3, 0, sizeof cnt3);

    forn(i,n){
        int mx = -1;
        vector<int> l;
        forn(j,3){
            char c; cin>>c;
            l.push_back(c-'a');
        }
        sort(all(l));
        l.erase(unique(all(l)), l.end());
        // vdbg(l);
        for(auto e : l) cnt1[e]++;
        if(sz(l)==2){
            cnt2[l[0]][l[1]]++;
        }else if(sz(l)==3){
            cnt2[l[0]][l[1]]++;
            cnt2[l[0]][l[2]]++;
            cnt2[l[1]][l[2]]++;
            cnt3[l[0]][l[1]][l[2]]++;
        }
        // cout<<endl;
    }

    ll ans = 0;
    forr(mask,1,(1<<24)){
        ll cua = 0;
        forn(i,24) if(on(mask, i)) {
            cua += cnt1[i];
            forr(j,i+1,24) if(on(mask,j)){
                cua -= cnt2[i][j];
                forr(k,j+1,24){
                    cua += cnt3[i][j][k];
                }
            }
        }
        ans ^= cua*cua;
    }

    cout<<ans<<endl;

    

    return 0;
}
