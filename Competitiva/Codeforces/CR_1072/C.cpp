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
    while(t--){
        ll n, k; cin >> n >> k;
        ll mi = n / 2, ma = (n + 1) / 2;
        int ans = -1, cont = 1;

        if(n == k) {
            cout << 0 << '\n';
            continue; //AAAAAAAAAAAAA
        }

        while(mi) {
            if(k >= mi and k <= ma) {
                ans = cont;
                break;
            }
            mi = mi / 2, ma = (ma + 1) / 2;
            cont++;
        }

        cout << ans << '\n';
    }

    return 0;
}