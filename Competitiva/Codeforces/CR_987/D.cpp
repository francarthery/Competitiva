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

vector<int> v;

struct UnionFind {
    vector<int> f;  // f[i] = parent of node i
    UnionFind(int n) : f(n, -1) {}
    int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }  // O(1)
    void join(int &i, int &j) {  // returns true if already in the same set
        int a = comp(i), b = comp(j);
        if (a != b) {
            if (v[a] > v[b]) swap(a, b);
            f[a] = b;  // the bigger group (b) now represents the smaller (a)
        }
    }
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifdef fran
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif

	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
        v.resize(n);
        vector<ii> pos(n);
        vector<int> vis(n);
		forn(i, n) {
            cin >> v[i];
            pos[i] = {v[i], i};
        }
        sort(rall(pos));
        vis = v;
		
        UnionFind uf(n);
        int n1 = n;
        forn(i, n){
            if(n1 <= pos[i].sc) continue;
            int j = pos[i].sc + 1, mi = pos[i].fr;
            while(j < n1 and pos[i].fr > vis[j]){
                uf.join(pos[i].sc, j);
                mi = min(mi, vis[j]);
                j++;
            }
            vis[pos[i].sc] = mi;
            n1 = pos[i].sc + 1;
        }

        forn(i, n) cout << v[uf.comp(i)] << ' ';
		cout << '\n';
	}

	
	return 0;
}