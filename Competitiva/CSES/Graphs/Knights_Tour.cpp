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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n"};
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int cubri = 1;
bool sigo = true;
vector<vector<int>> v(8, vector<int>(8));
vector<ii> mov{{1, 2}, {1, -2}, {2, 1}, {-2, 1}, {-1, 2}, {-1, -2}, {2, -1}, {-2, -1}};
bool in(int &i, int &j) {return i >= 0 and i < 8 and j >= 0 and j < 8; }

void optimo(int &x, int &y, vector<ii> &sig){
    forn(i, 8){
        int nx = x + mov[i].fr, ny = y + mov[i].sc, cont = 0;
        if(in(nx, ny) and v[nx][ny] == 0){
            forn(j, 8){
                int n2x = nx + mov[j].fr, n2y = ny + mov[j].sc;
                if(in(n2x, n2y) and v[n2x][n2y] == 0) cont++;
            }
            sig.pb({cont, i}); // Cuantos movimientos puedo hacer si voy ahi
        }
    }
    sort(all(sig));   
}

void f(int x, int y){    
    if(cubri == 64 or !sigo) {
        sigo = false;
        return;
    }

    vector<ii> sig;
    optimo(x, y, sig); //warnsdorf rule. el caballo siempre se tiene que mover a una pos con la menor cantidad de mov siguiente disponibles

    forn(i, sz(sig)){ //vector con cada movimiento posible ordenado asc por cantidad de movimientos disp desde esa pos
        int nx = x + mov[sig[i].sc].fr, ny = y + mov[sig[i].sc].sc;
        v[nx][ny] = ++cubri;
        f(nx, ny);
        if(!sigo) return;
        v[nx][ny] = 0;
        cubri--;
    }    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int x, y;
    cin >> x >> y;
    v[y - 1][x - 1] = 1;
    f(y - 1, x - 1);
    
    forn(i, 8) {
        forn(j, 8) cout << v[i][j] << ' ';
        cout << '\n';
    }
    

    return 0;
}