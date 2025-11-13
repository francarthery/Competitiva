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

    ll n, x, y;
    cin >> n >> x >> y;
    vector<ii> v(n);
    for(auto &[a, b] : v) cin >> a;
    for(auto &[a, b] : v) cin >> b;
    sort(all(v), greater<ii>());
    int cont1 = 0, cont2 = 0;
    while(cont1 < n and x >= 0){
        x -= v[cont1].fr;
        cont1++;
    }
    
    sort(all(v), [](ii &a, ii &b){
        return a.sc > b.sc;
    });

    while(cont2 < n and y >= 0){
        y -= v[cont2].sc;
        cont2++;
    }

    if(min(cont1, cont2) == n + 1) cont1--;
    cout << min(cont1, cont2) << '\n';

    
    return 0;
}