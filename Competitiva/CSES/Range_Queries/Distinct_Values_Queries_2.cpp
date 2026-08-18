#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

int main(/* int argc, char* argv[] */){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, q, a, b, t; cin >> n >> q;
    vector<int> v(n);
    map<int, int> compress;
    int cont = 1, clock = 0, nquery = 0;
    forn(i, n) {
        cin >> v[i];
        if(compress.count(v[i])) v[i] = compress[v[i]];
        else v[i] = compress[v[i]] = cont++;
    }
    int k = pow(n, 2.0/3.0);
    // dbg(k);
    // if(argc > 1) {
    //     k = atoi(argv[1]); // Lee k de los parámetros de ejecución
    // }
    vector<array<int, 4>> qu, upd;
    vector<int> ant = v;

    upd.push_back({(int)0, 0, 0, 0}); //query que no hace nada (perdon) para no tener problemas con el 0
    forn(i, q) {
        cin >> t >> a >> b; a--;
        if(t == 2) {
            if(compress.count(b)) b = compress[b];
            else b = compress[b] = cont++;
            upd.push_back({++clock, a, b, ant[a]}); //guardo quien pones en la pos y a quien pisaste
            ant[a] = b;
        }
        else {
            b--;
            qu.push_back({a, b, clock, nquery++});
        }
    }
    upd.push_back({(int)1e9, 0, 0, 0}); //techo para que quede cuando esta en las ultimas queries
    vdbg(v);
    sort(all(qu), [&](auto &a, auto &b) {
        if(a[0] / k != b[0] / k) return a[0] / k < b[0] / k;
        if(a[1] / k != b[1] / k) return (a[0]/k & 1) ? a[1]/k > b[1]/k : a[1]/k < b[1]/k;
        return (a[1]/k & 1) ? a[2] > b[2] : a[2] < b[2]; 
    });
 
    vector<int> count(cont), resp(sz(qu));
    int l = 0, r = -1, time = 0, ans = 0;
    
    auto add = [&](int &x) {
        count[x]++;
        if(count[x] == 1) ans++;
    };

    auto del = [&](int &x) {
        count[x]--;
        if(count[x] == 0) ans--;
    };
    // vdbg(v);

    forn(i, sz(qu)) {
        // cout << qu[i][0] << ' ' << qu[i][1] << ' ' << qu[i][2] << '\n';
        while(l > qu[i][0]) add(v[--l]);
        while(r < qu[i][1]) add(v[++r]); //asumo que r ya esta puesto. Arranco en -1? 
        while(l < qu[i][0]) del(v[l++]);
        while(r > qu[i][1]) del(v[r--]);

        while(qu[i][2] >= upd[time][0]) { //igual para aplicar la query de mi tiempo
            if(qu[i][0] <= upd[time][1] and qu[i][1] >= upd[time][1]) { //me afecta la update si esta en mi rango activo
                del(v[upd[time][1]]); //saco el elemento que estoy por cambiar
                add(upd[time][2]);
            }
            v[upd[time][1]] = upd[time][2];
            time++;
        }
        while(qu[i][2] < upd[time][0]) {
            if(qu[i][0] <= upd[time][1] and qu[i][1] >= upd[time][1]) { //me afecta la update si esta en mi rango activo
                del(v[upd[time][1]]); //saco el elemento que estoy por cambiar
                add(upd[time][3]); //valor anterior. retrocedo tiempo
            }
            v[upd[time][1]] = upd[time][3];
            time--;
        }

        resp[qu[i][3]] = ans;
        // dbg(qu[i][3]);
        // vdbg(v);
    }

    for(int i : resp) cout << i << '\n';
    

    return 0;
}