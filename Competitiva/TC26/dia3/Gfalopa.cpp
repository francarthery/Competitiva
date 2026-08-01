#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int(x.size()))
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x <<" = "; for(auto e  : x ) cout<<e<< ' ';}cout<<endl;
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
        freopen("in", "r", stdin);
        freopen("out","w", stdout);
    #endif

    int n; cin >> n;
    vector<ll> a(n), b(n);
    forn(i, n) cin >> a[i] >> b[i];
    ll denom = n, num = 0;

    multiset<ii> nums;
    bool ok = true;
    forn(i, n) nums.insert({a[i], b[i]});

    bool decision = false;
    dfor(i, 64) {
        set<ii> nuevo;
        for(auto j : nums) if((j.first ^ j.second) & (1ll << i)) {
            num++;
            decision = true;
        }
        else {
            nuevo.insert(j);
        }
    }

    ll xo = 0;
    if(decision == false){
        forn(i,n){
            xo ^= a[i] ^ b[i];
        }
    }

    if(!decision && !xo) cout << "0/1\n";
    else if(!decision && xo) cout<<"1/1\n";
    else cout << 1 << '/' << 2;

    return 0;
}