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

vector<vector<ii>> g;
vector<int> vis, topo;
vector<ii> dp;
int n, m, d, a, b, c, ma = 0;

void dfs(int s){
    if(vis[s]) return;
    vis[s] = true;

    for(ii &u : g[s]) dfs(u.fr);
    topo.pb(s);
}

bool f(int ma){
    dp[0] = {0, -1}; //min, ant
    for(int &i : topo){ //Recorro nodos en orden topologico
        for(ii &u : g[i]){
            if(u.sc <= ma and dp[u.fr].fr > dp[i].fr + 1){
                dp[u.fr] = {dp[i].fr + 1, i};
            }
        }
    }

    return dp[n - 1].fr <= d;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifdef fran
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif

	cin >> n >> m >> d;
	g.resize(n);
	vis.resize(n);
	forn(i, m){
		cin >> a >> b >> c; a--; b--;
		g[a].pb({b, c});
		ma = max(ma, c);
	}

    dfs(0);
    reverse(all(topo));

	int l = -1, r = ma + 1;
	while(r - l > 1){
		int m = (r + l) / 2;
		dp.assign(n, ii(1e9, -1));
		if(f(m)) r = m;	
		else l = m;
	}

	if(r <= ma){
        dp.assign(n, ii(1e9, -1));
		f(r);

		vector<int> ans;
		int elem = n - 1;
		while(elem != 0){
			ans.pb(elem);
			elem = dp[elem].sc;
		}
		ans.pb(0);

		reverse(all(ans));
		cout << sz(ans) - 1 << '\n';
		for(int &i : ans) cout << i + 1 << ' ';
		cout << '\n';
	}	
	else cout << -1 << '\n';

	
	return 0;
}