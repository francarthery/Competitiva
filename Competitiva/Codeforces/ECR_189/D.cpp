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

    int t; cin >> t;
    while(t--) {
        ll n, x; cin >> n >> x;
        const int MOD = 998244353;

        ll c0 = x / 4;
        ll c2 = (x + 2) / 4;
        ll c1 = (n - x + 1) / 4;
        ll c3 = (n - x + 1) / 4;
        ll sobra1 = (n - x + 1) % 4;
        ll sobra3 = (n - x + 1) % 4;
        int num1 = x % 4, num3 = x % 4;

        c1%=MOD; c2%=MOD; c3%=MOD; c0%=MOD;

        forn(i, sobra1) {
            if(num1 == 1) c1++;
            num1 = (num1 + 1) % 4;
        }
        forn(i, sobra3) {
            if(num3 == 3) c3++;
            num3 = (num3 + 1) % 4;
        }

        //dbg(c0); dbg(c1); dbg(c2); dbg(c3);
        cout << (c2 * c1 % MOD + (c0+1) * c3 % MOD) % MOD << '\n';
    }



    return 0;
}