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
        int p, q; cin >> p >> q;
        ll k = p + 2*q;

        int n = -1, m = -1;
        forr(i, 1, (k-1)/3+1) {
            int posn = i, posm = (k-i) / (2*i+1);
            if(posm < posn) break;
            if((k-i) % (2*i+1)) continue;
            if(posm - posn > p) continue;    
            n = posn, m = posm;
            break;
        }

        if(n == -1) cout << -1 << '\n';
        else cout << n << ' ' << m << '\n';
    }



    return 0;
}