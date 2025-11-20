#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

vector<int> esta, libs;
int x, y; //x = cantidad libros estante, y = cantidad cuadro y libros
bool f(int m){ //m cantidad de obras que entran
    int j = 0, cont = 0, cont2 = sz(esta) - m, ans = 0;
    if(cont2 < 0) return false;
    forn(i, sz(libs)){
        if(j >= sz(esta)) return false;
        if(libs[i] <= esta[j]) cont++;
        else return false;
        if(cont2){
            if(cont == x) cont = 0, j++, cont2--;
        }else{
            if(cont == y) cont = 0, ans++, j++;
        }
    }
    ans+= (sz(libs) - j);
    if(cont > y) ans--;
    return ans >= m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Lauty
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m; cin >> n >> m >> x >> y; //x cantidad libros en un estante, y cantidad de libros que caben en un estante al lado de una obra

    esta.resize(n), libs.resize(m);
    forn(i, n) cin >> esta[i];
   
    forn(i, m) cin >> libs[i];

    sort(rall(esta)), sort(rall(libs));

    int l = -1, r = 1e5 + 1;

    while(r - l > 1){
        int m = (r + l)/2;
        if(f(m)) l = m;
        else r = m;
    }

    if(l == -1) cout << "impossible";
    else cout << l;
    return 0;
}