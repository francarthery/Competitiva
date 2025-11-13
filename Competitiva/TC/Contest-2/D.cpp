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

    int t, n, m, r, c, rta = 0;
    cin >> t;
    while(t--){
        rta = 0;
        cin >> n >> m >> r >> c;
        rta = max(abs(r - 1) + abs(c - 1), abs(r - n) + abs(c - 1));
        rta = max(rta, abs(r - 1) + abs(c - m));
        rta = max(rta, abs(r - n) + abs(c - m));
        cout << rta << '\n';
    }

    
    return 0;
}