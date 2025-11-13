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
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, x, y;
    cin >> n >> x >> y;

    ll l = 0, r = 2e9 + 1;
    while(r - l > 1){
        ll m = (r + l) / 2;
        ll time = m - min(x, y), rest = (min(x, y) > m ? n : n - 1);
        rest -= (time / x);
        rest -= (time / y);
        if(rest <= 0) r = m; //si es negativo me sobro tiempo
        else l = m;        
    }

    cout << r << '\n';
    
    return 0;
}