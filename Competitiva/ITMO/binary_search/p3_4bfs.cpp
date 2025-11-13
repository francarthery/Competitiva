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
vector<int> dist, ant;
int n, m, d, a, b, c, ma = 0;

bool f(int ma){
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	
	while(sz(q)){
		int s = q.front();
		q.pop();

		for(ii &u : g[s]){
			if(dist[u.fr] == -1 and u.sc <= ma){
				q.push(u.fr);
				dist[u.fr] = dist[s] + 1;
				ant[u.fr] = s;
			}
		}
	}
	
	return dist[n - 1] != -1 and dist[n - 1] <= d;
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
	forn(i, m){
		cin >> a >> b >> c; a--; b--;
		g[a].pb({b, c});
		ma = max(ma, c);
	}

	int l = -1, r = ma + 1;
	while(r - l > 1){
		int m = (r + l) / 2;
		dist.assign(n, -1);
		ant.assign(n, 0);
		if(f(m)) r = m;	
		else l = m;
	}

	if(r <= ma){
		dist.assign(n, -1);
		ant.assign(n, 0);
		f(r);

		vector<int> ans;
		int elem = n - 1;
		while(elem != 0){
			ans.pb(elem);
			elem = ant[elem];
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