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

    int n, m; cin >> n >> m;
    vector<vector<int>> v(m, vector<int>(n));
    forn(i, m) forn(j, n) cin >> v[i][j], v[i][j]--;

    vector<vector<int>> inv(m, vector<int>(n));
    forn(i, m) forn(j, n) inv[i][v[i][j]] = j;

    int k = __lg(n) + 1;
    vector st(k, vector(m, vector(n, vector<int>(m, n-1)))); //tam salto, fila ini, col ini, col dest

    forn(i, m) forn(k, m) {
        int best = n-1;
        if(i != k) dfor(j, n) {
            st[0][i][j][k] = best;
            best = min(best, inv[k][v[i][j]]);
        }
    }

    forr(lvl, 1, k) forn(i, m) forn(j, n-1) forn(c, m) forn(mid, m) {
        st[lvl][i][j][c] = min(st[lvl][i][j][c], st[lvl-1][mid][st[lvl-1][i][j][mid]][c]);
    }

    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y; x--; y--;

        int dist = 2;
        vector<int> pos(m), goal(m); //pos mantiene las posiciones mas a la izq en la fila i luego de dist saltos
        forn(i, m) {
            goal[i] = inv[i][y];
            pos[i] = inv[i][x];
        }

        bool did = false, puedo = false;
        forn(i, m) if(pos[i] <= goal[i]) did = true;

        if(!did) dfor(i, k) {
            vector<int> npos = pos;
            forn(a, m) forn(b, m) {
                if(pos[b] == 1e9) continue;
                npos[a] = min(npos[a], st[i][b][pos[b]][a]);
            }

            forn(i, m) if(npos[i] <= goal[i]) did = true;
            if(!did) { //hago esto para quedar a 1 de dist del objetivo (igual al bin lifting del LCA)
                pos = npos;
                dist += (1 << i);
            }
            puedo |= did; //me guardo si realmente avance y me pasaba (significa que puedo)
            did = false;
        }
        else dist--;

        if(!puedo and !did) dist = -1;
        cout << dist << '\n';
    }



    return 0;
}