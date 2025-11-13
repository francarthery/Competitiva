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
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, a, b, c, tot, mi = INT_MAX;
    cin >> t;
    while(t--){
        tot = 0;
        mi = INT_MAX;
        cin >> a >> b >> c;
        tot += a;
        tot += b;
        tot += c;
        mi = min(mi, a);
        mi = min(mi, b);
        mi = min(mi, c);
        if(tot % 9 == 0 and tot / 9 <= mi) cout << "YES\n";
        else cout << "NO\n";

    }
    
    return 0;
}