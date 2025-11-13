#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

bool comp(tuple<int, int, int> &a, tuple<int, int, int>  &b){
    if(get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
    else return get<1>(a) > get<1>(b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Lauty
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<ii> aux(n);
    vector<tuple<int, int, int>> v(n);
    for(int i = n; i >= 1; i--){
        int x; cin >> x; x--;
        get<0> (v[x])+= i;
    }

    forn(i, n){
        int x; cin >> x;
        aux[i] = {x, i};
    }

    sort(rall(aux));

    forn(i, n){
        get<0>(v[aux[i].sc])+= n - i;
        get<1>(v[aux[i].sc]) = n - i;
        get<2>(v[aux[i].sc]) = aux[i].sc;
    }

    sort(all(v), comp);
    
    forn(i, n){
        cout << i + 1 << ". Kod";
        if(get<2>(v[i]) + 1 < 10) cout << "0";
        cout << get<2>(v[i]) + 1 << " (" << get<0>(v[i]) << ")" << '\n';
    }
    
    return 0;
}