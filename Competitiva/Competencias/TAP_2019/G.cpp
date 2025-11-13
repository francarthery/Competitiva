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

    int n, g;
    cin >> n;
    vector<int> v(n - 1);
    cin >> g;
    forn(i, n - 1) cin >> v[i];

    sort(all(v), greater<int>());
    forn(i, n - 1){
        g -= v.size() * v.back() - 1;
        v.pop_back();
        if(g < 0) break;
    }

    cout << (g > 0 ? "SI" : "NO") << '\n';
    
    return 0;
}