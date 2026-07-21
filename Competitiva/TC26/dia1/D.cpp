#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend9)()
#define dbg(x) cout<<#x <<" = " << x << endl;
#define vdbg(x) {cout<<#x<<" = ["; for(auto e : x) cout<<e<<' '; cout<<"\n";}
#define nl cout<<"\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int n; cin >> n;    
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    
    sort(all(v));
    ll sum = accumulate(all(v), 0ll);
    ll ans = sum;

    forr(i, 1, n){
        for(int j = 2; j * j <= v[i]; j++){
            if(v[i] % j) continue;
            ll cont = sum - v[i] - v[0];
            cont+= v[i] / j + v[0] * j;
            ans = min(cont, ans);
        }
    }

    cout << ans << '\n';
    return 0;
}