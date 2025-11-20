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
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        forn(i, n) cin >> a[i];
        forn(i, n) cin >> b[i];
        
        int res = 0;
        forn(i, n) if(a[i] == b[i]) res = i + 1; //ya estan bien
        map<int, vector<pair<int, bool>>> m; //elem, (indice, columna)
        forn(i, n){
            m[a[i]].pb({i, 0});
            m[b[i]].pb({i, 1});
        }

        for(auto i : m){
            forn(j, sz(i.sc) - 1){
                if(abs((i.sc)[j].fr - (i.sc).back().fr) > 1) res = max(res, (i.sc)[j].fr + 1); //a mas de 1
                else if(abs((i.sc)[j].fr - (i.sc).back().fr) == 1 and (i.sc)[j].sc == (i.sc).back().sc) res = max(res, (i.sc)[j].fr + 1); //estan a 1 no cruzados
            }
        }

        cout << res << '\n';

    }



    return 0;
}