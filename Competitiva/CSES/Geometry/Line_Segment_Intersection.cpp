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

ll cp(ll &x1, ll &y1, ll &x2, ll &y2, ll &x3, ll &y3){
    return ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
}

bool dentro(ll &x1, ll &y1, ll &x2, ll &y2, ll &x3, ll &y3){
    return (x3 >= min(x1, x2) and x3 <= max(x1, x2) and y3 >= min(y1, y2) and y3 <= max(y1, y2));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);    
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        bool rta = false;

        __int128_t cp1 = cp(x1, y1, x2, y2, x3, y3);
        __int128_t cp2 = cp(x1, y1, x2, y2, x4, y4);
        __int128_t cp3 = cp(x3, y3, x4, y4, x1, y1);
        __int128_t cp4 = cp(x3, y3, x4, y4, x2, y2);

        if(!cp1 and !cp2 and (dentro(x1, y1, x2, y2, x3, y3) or dentro (x1, y1, x2, y2, x4, y4))) rta = true;
        else if(!cp1 and dentro(x1, y1, x2, y2, x3, y3)) rta = true;
        else if(!cp2 and dentro(x1, y1, x2, y2, x4, y4)) rta = true;
        else if(!cp3 and dentro(x3, y3, x4, y4, x1, y1)) rta = true;
        else if(!cp4 and dentro(x3, y3, x4, y4, x2, y2)) rta = true;
        else if(cp1 * cp2 < 0 and cp3 * cp4 < 0) rta = true;

        cout << (rta ? "YES" : "NO") << '\n';
    }



    return 0;
}