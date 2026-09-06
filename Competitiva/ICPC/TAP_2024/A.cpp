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

vector<vector<int>> act(9);

int check(vector<int> &ini, vector<int> &tab) { //2 es que no paso nada, ni victoria ni empate
    forn(i, 3) {
        if(tab[i*3] == tab[i*3+1] and tab[i*3] == tab[i*3+2] and tab[i*3]) return tab[i*3];
        if(tab[i] == tab[3+i] and tab[i] == tab[6+i] and tab[i]) return tab[i];
        if(tab[0] == tab[4] and tab[0] == tab[8] and tab[0]) return tab[0];
        if(tab[2] == tab[4] and tab[2] == tab[6] and tab[2]) return tab[2];
    }
    forn(i, 9) if(!tab[i] and !ini[i]) return 2;
    return 0;
}

int f(vector<int> &ini, vector<int> &tab, bool turno) {
    int estado = check(ini, tab);
    if(estado != 2) return estado;

    int mov = (turno ? 1 : -1), res = (turno ? -1 : 1);
    forn(i, 9) {
        if(!tab[i] and !ini[i]) {
            tab[i] = mov;
            for(int j : act[i]) ini[j]--;
            if(turno) res = max(res, f(ini, tab, !turno));
            else res = min(res, f(ini, tab, !turno));
            for(int j : act[i]) ini[j]++;
            tab[i] = 0;
        }   
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    set<ii> pares;
    vector<int> ini(9);
    forn(i, n) {
        int a, b; cin >> a >> b; a--; b--;
        pares.insert({a, b});
    }
    
    for(auto i : pares) {
        act[i.first].push_back(i.second);
        ini[i.second]++; //1 es bloqueado
    }
    // forn(i, 9) vdbg(act[i]);
    // vdbg(ini);

    vector<int> tab(9);
    int res = f(ini, tab, 1);
    if(res == 1) cout << "X\n";
    else if(res == -1) cout << "O\n";
    else cout << "E\n";

    return 0;
}