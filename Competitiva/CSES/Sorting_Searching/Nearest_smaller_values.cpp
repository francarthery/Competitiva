#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        //freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> v(n);
    forn(i, n) cin >> v[i];

    vector<ii> st;
    vector<int> ans(n);
    forn(i, n){ //Calcula para cada elemento el menor a la izquierda. Hacer dfor si queremos el de la derecha
        while(sz(st) and st.back().fr >= v[i]) st.pop_back();
        if(sz(st)) ans[i] = st.back().sc + 1; 
        st.push_back({v[i], i});
    }

    for(int i : ans) cout << i << ' ';
    cout << '\n';

    return 0;
}