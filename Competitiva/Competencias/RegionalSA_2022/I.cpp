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
typedef pair<int, ii> iii;

int r, c;
set<iii> adj; //Me quedan por comer
set<int> proc; // Ya me los comi
vector<vector<int>> v;
vector<int> px{1, 0, -1, 0}, py{0, 1, 0, -1};

void vecinos(int x, int y){
    forn(i, 4){ 
        int nx = x + px[i], ny = y + py[i];
        if(nx >= 0 and nx < r and ny >= 0 and ny < c and !proc.count(v[nx][ny])) adj.insert({v[nx][ny], {nx, ny}});  
    }    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> r >> c;
    int ma = 0, x;
    v.assign(r, vector<int>(c));
    vector<bool> vis(r * c + 1);
    vector<ii> pos(c * r + 1);
    forn(i, r) forn(j, c) {
        cin >> x;
        v[i][j] = x;
        pos[x] = {i, j};
    }

    forr(t, 1, r * c + 1){ //Pruebo en todas las posiciones
        auto [i, j] = pos[t];
        if(vis[t] or ma >= r * c - t + 1) continue;
        vis[t] = true;
        adj.clear();
        proc.clear();
        int num = v[i][j], rta = 1;
        proc.insert(num);
        vecinos(i, j); //Calculo vecinos de inicial

        while(!adj.empty()){
            while(!adj.empty() and (adj.begin() -> fr < num)) {
                adj.erase(adj.begin()); //Si es menor lo saco
            }
            if(!adj.empty()){
                iii aux = *adj.begin();
                adj.erase(adj.begin());
                num = aux.fr;
                proc.insert(num);
                vis[num] = true;
                vecinos(aux.sc.fr, aux.sc.sc);
                rta++;
            }
        }
        ma = max(ma, rta);
    }

    cout << ma << '\n';
    
    return 0;
}