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
        //freopen("output.out", "w", stdout);
    #endif

    int n, h;
    cin >> n >> h;
    vector<int> v(n), aux;
    forn(i, n) cin >> v[i];

    int l = 0, r = n, m;
    while(l < r){
        aux.clear();
        m = (l + r + 1) / 2;
        forn(i, m) aux.pb(v[i]);
        sort(all(aux), greater<int>());
        int ind = 0, temp = h;
        forn(i, (m + 1) / 2){ //Cuidado
            temp -= aux[i * 2];
            if(temp < 0) break;
        }
        if(temp < 0) r = m - 1;
        else l = m;
    }

    cout << r << '\n';
    
    return 0;
}