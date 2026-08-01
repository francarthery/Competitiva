#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ws <<" "<<
#define nl cout<<"\n";
#define dbg(x) cout<<#x ws "=" ws x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' ';cout<<endl;}

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    int n, m; cin >> n >> m;
    priority_queue<pair<int, int>> pq;
    forr(i, 1, m + 1){
        int x; cin >> x;
        pq.push({x, i});
    }       

    vector<int> ans;
    while(sz(ans) < n - 1 and sz(pq) > 1){
        auto tope = pq.top();
        pq.pop();
        if(sz(ans) == n - 2){
            ans.push_back(tope.second);
            if(tope.first - 1 > 0) pq.push({tope.first - 1, tope.second});
            continue;
        }
        auto tope2 = pq.top();
        pq.pop();
        ans.push_back(tope.second);
        ans.push_back(tope2.second);
        if(tope.first - 1 > 0) pq.push({tope.first - 1, tope.second});
        if(tope2.first - 1 > 0) pq.push({tope2.first - 1, tope2.second});
    }

    if(sz(ans) != n - 1){
        cout << -1 << '\n';
        return 0;
    }
    bool ok = false;

    int comodin = -1;
    if(sz(ans) == n - 1){
        while(sz(pq)){
            auto tope = pq.top();
            comodin = tope.second;
            pq.pop();
            if(tope.second != ans[0] and tope.second != ans.back()){
                ans.push_back(tope.second);
                ok = true;
                break;
            }
        }
        if(!ok) ans.push_back(comodin);
    }
    
    if(comodin == -1){
        cout << "-1\n";
        return 0;
    }

    if(!ok){
        forn(i, n - 1){
            swap(ans[i], ans[n - 1]);
            if(ans[i] != ans[(i - 1 + n) % n] and ans[i] != ans[(i + 1) % n] and ans[n - 1] != ans[(n - 2 + n) % n] and ans[n - 1] != ans[0]){
                forn(i, n){
                    cout << ans[i] << ' ';
                }
                return 0;
            }
            swap(ans[i], ans[n - 1]);
        }
        cout << -1 << '\n';
    }
    else{
        forn(i, sz(ans)){
            cout << ans[i] << ' ';
        }
    }

    return 0;
}