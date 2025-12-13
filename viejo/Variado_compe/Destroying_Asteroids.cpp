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
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int r, c, k, rta = 0;
    cin >> r >> c >> k;
    map<int, int> m;
    forn(i, c){
        cin >> r;
        m[r]++;
    }
    vector<ii> v(all(m));
    sort(all(v), [](ii &a, ii &b){return a.second < b.second;});

    while(!v.empty() and k > 0){
        rta += v.back().sc;
        v.pop_back();
        k--;
    }

    cout << rta << '\n';

    return 0;
}