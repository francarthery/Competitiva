#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define nl cout<<"\n";
#define ws <<" "<<

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r",stdin);    
    freopen("out","w",stdout);
    #endif

    ll n, m; cin >> n >> m;
    vector<ll> c(n), w(n);
    vector<ii> ans(n);
    forn(i, n) cin >> c[i], ans[i].first = c[i] / 100, c[i] %= 100;
    forn(i, n) cin >> w[i];

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    ll angry = 0;
    forn(i, n) {
        if(c[i] == 0) continue;
        pq.push({(100 - c[i]) * w[i], i});
        ans[i].second = c[i];
        m -= c[i];
        while(sz(pq) and m < 0) {
            ii elem = pq.top();
            angry += elem.first;
            ans[elem.second].first++;
            ans[elem.second].second = 0;
            pq.pop();
            m += 100;
        }  
    }

    cout << angry << '\n';
    for(auto i : ans) cout << i.first << ' ' << i.second << '\n';


    return 0;
}


