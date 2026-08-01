#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(x) (int(x.size()))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define dbg(x) cout<<#x<<" = "<<x<<endl;
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
    freopen("out","w", stdout);
    #endif

    ll n, a, b, c; cin >> n >> a >> b >> c;
    ll ma = 0;
    forn(i, n+1) {
        forn(j, n+1) {
            ll res = a * i + j * b;
            if(res <= n and (n - res) % c == 0) {
                ll k = (n - res) / c;
                ma = max(ma, i+j+k);
            }
        }
    } 

    cout << ma << '\n';

    return 0;
}