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

    int n; cin >> n;
    vector<int> v(n);
    vector<__int128_t> alias(n+1), perm(n+1);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    forn(i, n) cin >> v[i];
    forr(i, 1, n+1) {
        ll p1 = rng();
        ll p2 = rng();
        alias[i] = (((__int128_t)p1 << 64) | p2);
        perm[i] = (perm[i-1] ^ alias[i]);
    }
    
    ll ans = 0;
    
    auto f = [&](vector<int> &v){
        vector<__int128_t> hash(n+1);
        forr(i, 1, n+1) hash[i] = (hash[i-1] ^ alias[v[i-1]]);
        
        forn(i, n) if(v[i] == 1) {
            int ma = 0;
            set<int> s;
            forr(j, i, n) {
                if(s.count(v[j])) break;
                s.insert(v[j]);
                ma = max(ma, v[j]);
                int l = j - (ma - 1);
                if(l >= 0 and l <= i and (hash[j+1] ^ hash[l]) == perm[ma]) {
                    ans++;
                    // cout << l << ' ' << j << '\n';
                }
            }
        }
    }; 
    
    f(v);
    reverse(all(v));
    cout << "pepito\n";
    f(v);

    forn(i, n) ans -= v[i] == 1;
    cout << ans << '\n';

    return 0;
}