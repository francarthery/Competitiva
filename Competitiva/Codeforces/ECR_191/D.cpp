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
        int n; cin >> n;
        vector<int> v(n);
        map<int, int> comp;
        forn(i, n) cin >> v[i];

        auto check = [&]() {
            vector<int> frec(n+1);
            int ant = -1;
            forn(i, n) {
                if(v[i] != ant and frec[v[i]]) return false;
                ant = v[i];
                frec[v[i]]++;
            }
            return true;
        };
        
        int ncomp = 0;
        forn(i, n) {
            if(comp[v[i]] == 0) v[i] = comp[v[i]] = ++ncomp;
            else v[i] = comp[v[i]];
        }

        vector<int> frec(n+1);
        int ant = -1, col = -1, cant = 0;
        forn(i, n) {
            if(col == -1 and v[i] != ant and frec[v[i]]) {
                col = v[i];
                cant = 2;
            }
            else if(v[i] == col and v[i] != ant) cant++;        
            frec[v[i]]++;
            ant = v[i];
        }


        if(cant > 3) {
            cout << "NO\n";
            continue;
        }

        set<int> pos;
        forn(i, n) if(v[i] == col) {
            if(i == 0 or v[i-1] != col or i==n-1 or v[i+1] != col) pos.insert(i);
            if(i and v[i-1] != col) pos.insert(i-1);
            if(i<n-1 and v[i+1] != col) pos.insert(i+1);
        }

        vector<int> pos2(all(pos));
        bool ok = false;
        forn(i, sz(pos2)) forr(j, i+1, sz(pos2)){
            swap(v[pos2[i]], v[pos2[j]]);
            ok |= check();
            swap(v[pos2[i]], v[pos2[j]]);
        }   

        cout << (ok or check() ? "YES" : "NO") << '\n';
    }


    return 0;
}