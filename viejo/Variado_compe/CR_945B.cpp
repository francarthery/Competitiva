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
#define MAXL 21

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        int val = 0, l = 1, r = n, m; 
        bool ok;
        forn(i, n) val |= v[i];//valor que tiene que dar cada sublista

        while(l < r){
            m = (l + r) / 2;
            ok = true;
            vector<int> bits(MAXL);
            forn(i, m)
                forn(mask, MAXL) 
                    if(v[i] & (1 << mask)) 
                        bits[mask]++;
            
            forn(mask, MAXL) //verifico que bits tenga el mismo valor que val
                if((bool)bits[mask] != (bool)(val & (1 << mask))) {
                    ok = false;
                    break;
                }
            
            forn(i, n - m){
                if(!ok) break;

                forn(mask, MAXL){ //Saco el primero y pongo el ultimo
                    if(v[i] & 1 << mask) bits[mask]--;
                    if(v[i + m] & 1 << mask) bits[mask]++;
                }
                forn(mask, MAXL) //verifico que bits tenga el mismo valor que val
                    if((bool)bits[mask] != (bool)(val & (1 << mask))) {
                        ok = false;
                        break;
                    }
            }

            if(ok) r = m;
            else l = m + 1;
        }

        cout << l << '\n';
    }
    
    return 0;
}