#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define forall(i, a) for(auto i = a.begin(); i != a.end(); i++)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto  e : x) cout<<e<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

// vector<int> dp(n), tam(n), f(n);
//     vector<ll> sfat(n);
//     vector<ll> ans(n);
//     vector<vector<int>> g(n);

const int N = 1e6+4;
int dp[N], tam[N], f[N], d[N];
ll sfat[N], ans[N];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    
    int n; cin >> n;
    vector<ii> ar(n-1);
    forn(i, n-1) {
        int x; cin >> x; x--;
        ar[i] = {x, i+1};
    }   
    vector<int> ini(n);
    sort(all(ar));
    int ant = -1;
    forn(i, n) {
        if(ar[i].first > ant) {
            ini[ar[i].first] = i;
            ant = ar[i].first;
        }
    }

    dfor(s, n) {
        tam[s] = 1;
        vector<int> sons;
        int i = ini[s];
        while(i < n-1 and ar[i].first == s) {
            int u = ar[i++].second;
            sons.push_back(f[u]);
            dp[s] = max(dp[s], dp[u]);
            
            ans[s] += ans[u] + tam[u];
            tam[s] += tam[u];
        }
        sort(sons.rbegin(), sons.rend());

        if(sz(sons)) dp[s] = max(dp[s], sons[0] + 1);
        if(sz(sons) > 1) dp[s] = max(dp[s], sons[0] + sons[1] + 2);
        
        ll resp = 0;
        if(sz(sons)) resp = sons[0] + 1;
        f[s] = resp;
    }
    // f.clear();

    ll tot = 0;
    forn(s, n) {
        ll sum = ans[s] + sfat[s];
        tot += sum;
        int i = ini[s];
        while(i < n-1 and ar[i].first == s) {
            int u = ar[i++].second;
            sfat[u] = sum - (ans[u] + tam[u]) + (n - tam[u]);
        } 
    }
    
    cout << tot/2ll << '\n';
    forn(i, n) cout << dp[i] << (i == n-1 ? '\n' : ' ');

    return 0;
}