#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        set<int> s;
        forn(i, n) {
            cin >> v[i];
            s.insert(v[i]);
        }

        if(sz(s) > k) {
            cout << -1 << '\n';
            continue;
        }

        forn(i, n) if(sz(s) < k and !s.count(i+1)) s.insert(i+1);

        cout << n * sz(s) << '\n';
        vector<int> ans{all(s)};
        forn(i, n) forn(j, sz(s)) cout << ans[j] << ' ';
        cout << '\n';
    }

    
    return 0;
}