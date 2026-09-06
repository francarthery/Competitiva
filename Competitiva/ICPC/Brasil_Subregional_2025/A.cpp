#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=(a); i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<< "\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out","w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));
    forn(i, n) forn(j, m) cin >> v[i][j];
    vector<ll> ma(m);
    forn(i, m) forn(j, n) ma[i] = max(ma[i], v[j][i]);
    cout << accumulate(all(ma), 0ll) << '\n';

}