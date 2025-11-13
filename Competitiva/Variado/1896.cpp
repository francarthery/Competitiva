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

int n, a, d, h;
bool rta = false;
vector<tuple<int, int, int>> v;

void f(int x, int y, int z, int cant){
    if(v.empty()){
        if(!rta and cant > 1) rta = (x == a and y == d and z == h);
        return;
    }

    auto [a1, b1, c1] = v.back();
    v.pop_back();
    f(x, y, z, cant);
    f(x + a1, y + b1, z + c1, cant + 1);
    v.pb({a1, b1, c1});
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n >> a >> d >> h;
    v.resize(n);
    for(auto &[x, y, z] : v) cin >> x >> y >> z;

    f(0, 0, 0, 0);
    cout << (rta ? 'Y' : 'N') << '\n';
    
    return 0;
}