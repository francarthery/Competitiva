#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int) (x).size())
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto e : x) cout<<e<<" ";cout<<endl;}
using namespace std;

typedef long long ll;
typedef pair<int,ll> ii;
int n, k;
unordered_map<ll, ii> dp; //mod, freq
vector<int> ans;

ii solve(ll pos, ll mod, ll num, ll frec){
    ll estado = ((mod << 52) | frec);
    if(pos == n) return {mod, num};
    if(dp.count(estado)) return dp[estado];
    
    ii best = {-1, -1};
    for(int i = 9; i >= 1; i--){
        ll fi = ((frec >> ((i-1) * 5)) & 31ll);
        if(fi){
            ll nf = (frec & (~(31ll << ((i-1) * 5))));
            fi--;
            nf |= (fi << ((i-1) * 5));
            num*= 10;
            num+= i;
            int nmod = num % k;
            best = max(best, solve(pos + 1, nmod, num, nf));
            num-=i;
            num/=10;
        }
    }

    return dp[estado] = best;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    cin >> n >> k;
    vector<ll> v(10);
    ans.resize(k, -1);
    forn(i, n){
        int x; cin >> x;
        v[x]++;
    }

    //ii ans = solve(0, 0, 0);

    //cout << ans.first << ' ' << ans.second << '\n';
    ll frec = 0;
    forr(i, 1, 10) {
        frec |= (v[i] << (i-1)*5);
        // dbg(frec);
    }
    // vdbg(v);
    // dbg(frec);
    cout << solve(0, 0, 0, frec).second << '\n';
    

}