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
#define vdbg(x) {cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Lauty
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll d, c;
    cin >> d >> c;
    
    if(d - c > c - 2){
        cout << "impossible\n";
        return 0;
    }

    ll l = -1, r = c / 2;
    while(r - l > 1){
        ll m = (l + r) / 2;
        ll val = c + c * m - (m * (m + 1));
        //dbg(m); dbg(val);

        if(val >= d) r = m;
        else l = m;
    }

    cout << r << '\n';

    
    return 0;
}