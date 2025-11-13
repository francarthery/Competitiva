#include <bits/stdc++.h>
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(ll i=n-1;i>=0;i--)
#define sz(a) (ll(a.size()))
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define vdbg(x) cout<<#x<<": [";for(auto e:x)cout<<e<<", ";cout<<endl;
#define ws <<" "<<
#define nl cout<<"\n";

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>t(n), d(n);
        set<ii>elem;
        vector<ll>ans;
        map<ll,ll>tiene;
        forn(i,n){
            cin>>t[i]>>d[i];
            elem.insert({i,t[i]});
            tiene[d[i]]+=t[i];
        }

        auto copia=d;
        sort(all(copia));
        vector<ii>sacar;
        
        ll T=0;
        for(auto [lim,sum]:tiene){
            for(auto par:sacar){
                elem.erase(elem.find(par));
            }
            sacar.clear();
            ll aux=0;
            for(auto [ind,tie]:elem){
                if(d[ind]==lim){
                    cout<<"pongomismo" ws tie;nl;
                    //siosi
                    if(lim-T-tie<0){
                        cout<<'*';nl;
                        return 0;
                    }
                    ans.push_back(ind);
                    T+=tie;
                    aux+=tie;
                    sacar.push_back({ind,tie});
                    if(aux==sum)break;
                } else { 
                    dbg(lim);
                    dbg(T);
                    dbg(sum);
                    dbg(aux);
                    dbg(tie);
                    if(lim-T-sum+aux-tie<0)continue;
                    ans.push_back(ind);
                    T+=tie;
                    sacar.push_back({ind,tie});
                }
            }
        }

        if(sz(ans)!=n){
            cout<<"*";nl;
            return 0;
        }

        for(auto e:ans)cout<<e+1<<' ';
        nl;
    }
    
    return 0;
}