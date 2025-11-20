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
#define fsp(x) fixed << setprecision((x))

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;

    while(t--){
        int n = 3;
        vector<ii> v(n);
        forn(i, n) cin >> v[i].fr >> v[i].sc;
        //hago bitmask si 1, b = a, sino a = b
        //despues pruebo las combinaciones
        
        __int128_t ans = 9e18 + 1; //entra? 
        forn(i, (1 << n)){
            vector<ii> aux(n);
            forn(j, n){
                if(i & (1 << j)){ //1 b = a
                    aux[j] = {v[j].sc, v[j].fr};
                }else{
                    aux[j] = v[j];
                }
            }

            ans = min(ans, (__int128_t)(aux[0].fr + aux[1].fr + aux[2].fr) * max({aux[0].sc, aux[1].sc, aux[2].sc}));
            vector<int> ord{0, 1, 2};
            do{
                ll x = max(aux[ord[0]].sc + aux[ord[1]].sc, aux[ord[2]].sc);
                ll y = 1e10;
                if(aux[ord[2]].sc <= aux[ord[0]].sc) y = min(y, max(aux[ord[2]].fr + aux[ord[0]].fr, aux[ord[1]].fr));
                if(aux[ord[2]].sc <= aux[ord[1]].sc) y = min(y, max(aux[ord[2]].fr + aux[ord[1]].fr, aux[ord[0]].fr));
                if(aux[ord[2]].sc > aux[ord[1]].sc and aux[ord[2]].sc > aux[ord[0]].sc) 
                    y = min(y, max(aux[ord[1]].fr, aux[ord[0]].fr) + aux[ord[2]].fr);

                //dbg(x); dbg(y);
                ans = min(ans, (__int128_t)x * y);

            } while(next_permutation(all(ord)));
        }

        cout << (ll)ans << '\n';
    }


    return 0;
}