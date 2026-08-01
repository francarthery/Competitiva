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
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        ll ma = *max_element(all(v));

        int ans = 0, mae = 0;
        dfor(i, n) {
            if(v[i] == ma) break;
            if(v[i] > mae) {
                mae = v[i];
                ans++;
            }
        }

        cout << ans << '\n';
    }
    

    return 0;
}