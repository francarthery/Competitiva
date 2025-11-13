#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "\b]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n, u, r, d, l, u2, r2, d2, l2;
    cin >> t;
    while(t--){
        cin >> n >> u >> r >> d >> l;
        u2 = u; r2 = r; l2 = l; d2 = d;

        if(u == n){
            r2--;
            l2--;
        }
        else if(u == n - 1) (r2 > l2 ? r2-- : l2--);
        if(d == n){
            r2--;
            l2--;
        }
        else if(d == n - 1) (r2 > l2 ? r2-- : l2--);
        if(r == n){
            u2--;
            d2--;
        }
        else if(r == n - 1) (u2 > d2 ? u2-- : d2--);
        if(l == n){
            u2--;
            d2--;
        }
        else if(l == n - 1) (u2 > d2 ? u2-- : d2--);

        cout << (u2 < 0 or l2 < 0 or r2 < 0 or d2 < 0 ? "NO" : "YES") << '\n';
    }

    
    return 0;
}