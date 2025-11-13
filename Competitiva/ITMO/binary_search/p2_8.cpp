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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll a1, a2, a3, b1, b2, b3, c1 = 0, c2 = 0, c3 = 0;
    ll ru;
    string s; cin >> s;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> ru;
    for(char &c : s){
        if(c == 'B') c1++;
        else if(c == 'S') c2++;
        else c3++;
    }

    ll l = -1, r = 1e14;
    while(r - l > 1){
        ll m = (r + l) / 2; 
        if(max(c1 * m - a1, 0ll) * b1 + max(c2 * m - a2, 0ll) * b2 + max(c3 * m - a3, 0ll) * b3 <= ru) l = m;
        else r = m;
    }
    
    cout << max(0ll, l) << '\n';

    return 0;
}