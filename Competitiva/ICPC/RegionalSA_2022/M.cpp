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

int r, c;
vector<string> v;
vector<ii> mov{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<bool>> vis;

void dfs(vector<ii> &pos){
    
    forn(i, 4){
        vector<ii> npos;
        forn(j, sz(pos)){
            int nx = pos[j].fr + mov[i].fr, ny = (pos[j].sc + mov[i].sc + c) % c;
            if(nx >= 0 and nx <= r + 1 and v[nx][ny] == '0') npos.pb({nx, ny});
            else break;
            if(!j and vis[nx][ny]){
                npos.clear();
                break; //Si no visite la pos
            }
        }
        if(sz(npos) == sz(pos)){
            int nx = pos[0].fr + mov[i].fr, ny = (pos[0].sc + mov[i].sc + c) % c;
            vis[nx][ny] = 1;
            dfs(npos);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s;
    cin >> r >> c >> s;
    vector<ii> pos, posr;
    v.resize(r + 2);
    v[0] = v[r + 1] = string(c, '0');
    forr(i, 1, r + 1) cin >> v[i];
    forn(i, sz(s)) if(s[i] == '1') { pos.pb({0, i}), posr.pb({0, c - 1 - i}); };

    bool flag = false;
    if(!pos.empty()) {
        vis.assign(r + 2, vector<bool>(c));
        vis[pos[0].fr][pos[0].sc] = 1;
        dfs(pos); 
        forn(i, c) flag |= vis[r + 1][i];
        if(!flag){
            vis.assign(r + 2, vector<bool>(c));
            vis[posr[0].fr][posr[0].sc] = 1;
            dfs(posr); 
        }    
        forn(i, c) flag |= vis[r + 1][i];
    }
    
    cout << (flag or !sz(pos)? "Y" : "N") << '\n';
    
    return 0;
}