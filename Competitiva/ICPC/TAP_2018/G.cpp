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

    int n, rta = 0;
    cin >> n;
    vector<ii> v(n);
    ii p1, p2;
    for(auto &[i, j] : v) cin >> i >> j;

    forn(i, n) forn(j, n) forn(k, n){
        if(i != j and j != k and k != i){
            p1 = {v[j].fr - v[i].fr, v[j].sc - v[i].sc};
            p2 = {v[k].fr - v[i].fr, v[k].sc - v[i].sc};
            if(p1.fr * p2.fr + p1.sc * p2.sc == 0) rta++;
        }
    }

    cout << rta / 2 << '\n';
    
    return 0;
}