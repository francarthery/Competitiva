#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n; cin >> n;
    vector<ll> ans;

    int ma = 0;
    forn(i, 32) if(n & (1ll << i)) ma = i;

    int bits = 0;
    while(bits <= ma){
        int val = 0;
        forn(i, 7){
            val |= (n & (1ll << i));
            bits++;
        }
        n >>= 7;
        ans.pb(val);
    }
    //ans.pop_back();
    //vdbg(ans);
    reverse(all(ans));

    int cont = 1;
    forn(i, sz(ans) - 1){
        ans[i] |= (1ll << 7); 
    }

    forn(i, sz(ans)) cout << ans[i] << ' ';



    return 0;
}