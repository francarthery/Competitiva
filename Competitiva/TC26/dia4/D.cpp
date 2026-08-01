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
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector<int> v(2 * n);
        forn(i, 2 * n) cin >> v[i];
        int cont = 0;
        map<int, int> dif;
        for(int i = 2 * n - 1; i >= n; i--){
            cont+= (v[i] == 1 ? 1 : -1);
            dif[cont] = i - n;
        }
        if(!dif.count(0)) dif[0] = n;
        vector<int> v2(n);
        cont = 0;
        bool ok = true;
        forn(i, n){
            cont+= (v[i] == 1 ? 1 : -1);
            v2[i] = cont;
            if(!cont) ok = false;
        }

        int ans = 2 * n;

        if(ok) ans = min(ans, dif[0] + n);
        for(int i = n - 1; i >= 0; i--){
            if(dif.count(-v2[i])) ans = min(ans, dif[-v2[i]] + n - i - 1);
        }

        cout << ans << '\n';
    }

    return 0;
}