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
    while(t--) {
        int n, m; cin >> n >> m;
        bool ok = true;

        vector<ii> ev;
        forn(i, n) {
            int x; cin >> x; 
            ev.push_back({x, 0});
        }
        forn(i, m) {
            int x; cin >> x; 
            ev.push_back({x, 1});
        }
        sort(all(ev));
        int abre = 0, cerro = 0, pend = m;
        
        forn(i, n+m) {
            if(ev[i].second == 0) {
                if(pend) {
                    pend--;
                    abre++;
                }else if(cerro) cerro--;
            }
            else {
                if(!abre) ok = false;
                else {
                    abre--;
                    cerro++;
                }
            }
        }

        if(cerro > 0) ok = false;

        cout << (ok ? "YES" : "NO") << '\n';
    }


    return 0;
}