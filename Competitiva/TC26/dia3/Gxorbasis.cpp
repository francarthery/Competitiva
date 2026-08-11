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
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out","w", stdout);
    #endif

    int n; cin >> n;
    vector<ll> a(n), b(n);
    ll xa = 0;
    forn(i, n) {
        cin >> a[i] >> b[i];
        xa ^= a[i];
    }

    vector<ll> base(63);
    auto add = [&](ll x) {
        dfor(i, 63) {
            if((x >> i) & 1) {
                if(base[i]) x ^= base[i];
                else {
                    base[i] = x;
                    return x;
                }
            }
        }
        return 0ll;
    };

    forn(i, n) add(a[i] ^ b[i]);    
    if(add(xa)) {
        cout << "1/1\n";
        return 0;
    }
    
    int tam = 0;
    forn(i, 63) tam += base[i] != 0;
    
    cout << (1ll << tam) - 1 << '/' << (1ll << tam) << '\n';

    return 0;
}