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

struct UnionFind{
    int nsets;
    vector<int> f, setsz;
    UnionFind(int n) : nsets(n), f(n,-1), setsz(n,1) {}
    int comp(int x) {
        return (f[x] == -1 ? x : f[x] = comp(f[x]));
    }
    bool join(int u, int v){
        int a = comp(u);
        int b = comp(v);
        if(a!=b){
            if(setsz[a] > setsz[b]) swap(a,b);
            f[a] = b;
            nsets--, setsz[b] += setsz[a];
        }
        return a==b;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r", stdin);
    freopen("out","w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<pair<ll, ii>> ar(m), ar2;
        UnionFind uf(n);
        int a, b, c;
        forn(i, m) {
            cin >> a >> b >> c; a--; b--; 
            ar[i] = {c, {a, b}};
        }
        ll suma = 0, ma = -1;
        sort(all(ar));

        forn(i, m) {
            if(!uf.join(ar[i].second.first, ar[i].second.second)){
                if(ar[i].first > k) {
                    suma += ar[i].first - k;
                }
                ma = max(ma, (ll)ar[i].first);
            }
            else ar2.push_back(ar[i]);
        }
        
        if(ma < k) {
            ll best = k - ma;
            forn(i, sz(ar2)) best = min(best, abs(ar2[i].first-k)); 
            suma = best;
        }

        cout << suma << '\n';
    }


    return 0;
}