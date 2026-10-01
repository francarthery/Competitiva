#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto e : x) cout<<e<<" ";cout<<endl;}
using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n; cin >> n;
    vector<ll> psc(n+1), psv(n+1);
    forn(i, n) {
        cin >> psc[i+1] >> psv[i+1];
        psc[i+1] += psc[i];
        psv[i+1] += psv[i];
    }
    // vdbg(psc); vdbg(psv);

    int q; cin >> q;
    forn(i, q) {
        ll a; cin >> a;
        long double cc = psc[a];
        long double vv = psv[a];
        
        long double val = (cc - vv) / (cc + vv);

        if(val > 0) cout << "COMPRA\n";
        else if(val < 0) cout << "VENDA\n";
        else cout << "NEUTRO\n";
    }
    

    return 0;
}