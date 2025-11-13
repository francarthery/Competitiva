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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
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

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];

        int ma1 = -1e9, ma2 = -1e9, ma3 = -1e9, ma4 = -1e9, mi1 = 1e9, mi2 = 1e9, mi3 = 1e9, mi4 = 1e9, cont = 0, pos = n;
        forn(i, n) if(abs(v[i]) != 1) pos = i;
        //rango izquierda
        forn(i, pos) {
            if(cont + v[i] > 0) cont += v[i];
            else cont = 0;
            ma1 = max(ma1, cont);
        }
        cont = 0;
        forn(i, pos) {
            if(cont + v[i] < 0) cont += v[i];
            else cont = 0;
            mi1 = min(mi1, cont);
        }

        //rango derecha
        cont = 0;
        forr(i, pos + 1, n) {
            if(cont + v[i] > 0) cont += v[i];
            else cont = 0;
            ma2 = max(ma2, cont);
        }
        cont = 0;
        forr(i, pos + 1, n) {
            if(cont + v[i] < 0) cont += v[i];
            else cont = 0;
            mi2 = min(mi2, cont);
        }

        if(pos != n){
            cont = 0;
            for(int i = pos; i >= 0; i--){
                cont += v[i];
                ma3 = max(ma3, cont);
                mi3 = min(mi3, cont);
            }
            cont = 0;
            forr(i, pos, n){
                cont += v[i];
                ma4 = max(ma4, cont);
                mi4 = min(mi4, cont);
            }

            mi3 = -v[pos] + mi3 + mi4;
            ma3 = -v[pos] + ma3 + ma4;
        }    
        set<int> s{0};
        forr(i, mi1, ma1 + 1) s.insert(i);
        forr(i, mi2, ma2 + 1) s.insert(i);
        forr(i, mi3, ma3 + 1) s.insert(i);
     
        cout << sz(s) << '\n';
        for(int i : s) cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}