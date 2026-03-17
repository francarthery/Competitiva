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

vector<vector<int>> g;
struct Trie {
    Trie* m[16] = {};  
    bool termina = 0;

    int get_id(char &c) {
        if(c >= '0' and c <= '9') return c - '0';
        else return c - 'a' + 10;
    }

    void add(string &s, int p, int f) {
        int id = get_id(s[p]);
        if(m[id] == nullptr) m[id] = new Trie();
        m[id]->termina = true;

        for(int u : g[p]) {
            if(u != f) m[id] -> add(s, u, p);
        }
    }

    int dfs() {
        int cant = termina;
        for(auto i : m) if(i != nullptr) cant += i -> dfs();
        return cant;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    string s; cin >> s;
    g.resize(n);

    int a, b;
    forn(i, n-1) {
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    Trie tr;
    forn(i, n) tr.add(s, i, -1);

    cout << tr.dfs() << '\n';

    return 0;
}