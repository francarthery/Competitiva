
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) (int(x.size))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' '; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

ll guita = 0;

int prg(ll x){
    // #ifdef fran
    //     ll limite = 70368744177665ll;
    //     if(x <= limite) guita += x;
    //     return (x <= limite);
    // #endif
    cout<< "?" ws x<<endl;
    string s;cin>>s;
    if(s == "Lucky!"){
        guita += x;
        return 1;
    }
    else if(s == "Fraudster!") 
        return 0;
    else exit(0);
}

void rta(ll x){
    cout<<"!" ws x<<endl;
}

void solve(){
    ll cnt = 0, salto = 1, tope = 2e18, piso = 0, guita = 0;
    while(1){
        int rta = prg(salto); cnt++;
        if(rta){
            piso = salto;
        } else {
            tope = salto;
            salto /= 2;
            if(salto > 1)salto /= 2;
            break;
        }
        salto *= 2;
    }

    while(piso + 1 < tope){
        while(guita < piso + salto) {
            prg(piso);
            guita += piso;
            cnt++;
        }
        int rta = prg(piso + salto); cnt++;
        if(rta) {
            piso += salto;
        } else {
            tope = piso + salto;
        }
        salto /= 2;
    }
    // dbg(cnt);
    rta(piso);
}

int main(){

    int t;cin>>t;
    while(t--){
        guita = 0;
        solve();
    }    

    return 0;
}