#include <bits/stdc++.h>
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(ll i=n-1; i>=0; i--)
#define sz(x) ((ll)(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' '; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
#define popcnt(x) (__builtin_popcount(x))
#define on(x, b) (x & (1ll<<b))
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif


    int n,m;
    cin>>n>>m;
    int o = 0;
    int cc = 0;
    int vv=1;
    map<string, int> idx;
    vector<vector<int>> pconsulta(cc);
    forn(i,n){
        int x;cin>>x;
        if(x == 2){
            if(vv==1) {
                cc++;
                pconsulta.push_back({});
            }
            vv=0;
            string s;cin>>s;
            if(idx.count(s) == 0){
                idx[s] = o++;
            }
            pconsulta[cc-1].push_back(idx[s]);
        } else {
            vv=1;
        }
    }

    vector<ll> solapa(m);

    forn(i,cc){
        ll ma = 0;
        for(auto e : pconsulta[i]){
            ma |= (1ll<<e);
        }
        for(auto e : pconsulta[i]){
            solapa[e] |= ma;
            if(on(solapa[e],e)) solapa[e] ^= (1ll<<e);
        }

    }

    vector<vector<ll>> rta1(21), rta2(21);
    ll rta=0;

    forr(ma,1,1<<min(20,m)){
        bool f=1;
        forn(bit, min(20,m)){
            if(solapa[bit] & ma){
                f=0;
                break;
            }
        }
        if(!f)continue;
        rta1[popcnt(ma)].push_back(ma);
        rta = max(rta, (ll)popcnt(ma));
    }

    forr(ma,1,1<<max(0,min(20, m-20))){
        ma<<=20;
        bool f = 1;
        forr(bit,20,min(40,m)){
            if(solapa[bit] & ma){
                f = 0;
                continue;
            }
        }
        if(!f) continue;
        rta2[popcnt(ma)].push_back(ma);
        rta = max(rta, (ll)popcnt(ma));
    }


    auto check = [&] (ll ma1, ll ma2) -> bool { 
        //ma1, primeros 20 prendidos
        //ma2 ultimos 20 vivos
        // dbg(ma1);
        // dbg(ma2);
        forn(bit1,20) if(on(ma1,bit1)) {
            if(solapa[bit1] & ma2){
                //alguno que solapa con bit1 esta vivo en los ultimos 20
                return false;
            }
        }
        // dbg(popcnt(ma1) + popcnt(ma2));
        return true;
    };
    
    ll lo = rta, hi = m+1;
    while(hi - lo > 1){
        int tot = (lo+hi)/2;
        bool f=0;
        forr(primer,1,21){
            int segun = tot - primer;
            // dbg(primer);a
            // dbg(segun);
            // dbg(tot);
            if(primer <= 0)continue;
            if(segun <= 0) continue;
            if(primer > 20 || rta1[primer].empty()) continue;
            if(segun > 20 || rta2[segun].empty()) continue;
            for(auto &ma1 : rta1[primer]){
                for(auto &ma2 : rta2[segun]){
                    if(check(ma1,ma2)) f=1;
                } 
                if(f)break;
            }
            if(f)break;
        }
        if(f) lo=tot;
        else hi=tot;
    }
    rta = max(rta, lo);

    cout<<rta<<endl;
    
    return 0;
}