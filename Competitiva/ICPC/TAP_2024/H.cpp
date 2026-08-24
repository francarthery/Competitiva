#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) forr(i,0,n)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x){cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define ws <<' '<<
#define nl cout << '\n';

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

	ll n,m; 
	cin>>n>>m;
	
	vector<array<ll,5>> ev;
	vector<int> f(n+1), p(n+1);
	f[n]=-1;
	vector<ii> cae(m);
	const int IZ=1,DE=0,PU=2; //[,)
	const int inf=1e9;
	
	forn(i,n){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		ev.push_back({x1,IZ,y1,y2,i});
		ev.push_back({x2,DE,y1,y2,i});
	}
	ev.push_back({-2*inf,IZ,-2*inf,2*inf,n});
	ev.push_back({2*inf,DE,-2*inf, 2*inf,n});
	//limite hor, tipo, abajo, arriba, indice
	
	forn(i,m) {
		cin>>cae[i].first>>cae[i].second;
		ev.push_back({cae[i].first,PU,cae[i].second});
	}
	
	sort(all(ev));
	set<tuple<int,int,bool>> act;
	//piso, techo, id
	
	forn(i,sz(ev)){
		auto [izq, tipo, piso, techo, id] = ev[i];
		if(tipo == IZ){
			if(i != 0) {
				auto it = act.upper_bound({piso,inf,inf});
				auto [low, idu, tip] = *it;
				if(tip){
					f[id] = idu;
				} else {
					f[id] = f[idu];
				}
			}
			act.insert({piso,id,0});
			act.insert({techo,id,1});
		} else if(tipo == DE) {
			act.erase({piso,id,0});
			act.erase({techo,id,1});
		} else {
			auto it = act.upper_bound({piso,inf,inf});
			auto [low, idu, tip] = *it;
			if(tip){
				p[idu]++;
			} else {
				p[f[idu]]++;
			}
		}
	}
	
	vector<vector<int>> g(n+1);
	forn(u,n+1){
		int fat = f[u];
		if(fat==-1)continue;
		g[fat].push_back(u);
	}

    vector<ii> nodo(n+1);
    ll ans = 0;
    auto dfs1 = [&](auto &&f, int s) -> void {
        nodo[s].first = p[s];
        for(int u : g[s]) {
            f(f, u);
            nodo[s].first += nodo[u].first;
            nodo[s].second += nodo[u].second + nodo[u].first;
        }
    };

    auto dfs2 = [&](auto &&f, int s, ii fat) -> void {
        ans += p[s] * fat.second + p[s] * nodo[s].second;
        fat.first += nodo[s].first;
        fat.second += nodo[s].second;

        for(int u : g[s]) {
            fat.first -= nodo[u].first;
            fat.second -= nodo[u].second + nodo[u].first - fat.first;
            f(f, u, fat);
            fat.second += nodo[u].second + nodo[u].first - fat.first;
            fat.first += nodo[u].first;
        }
    };

    dfs1(dfs1, n);
    dfs2(dfs2, n, ii(0, 0));

	cout << fixed << setprecision(14) << (long double)(ans) / (m*m) << '\n';
	
	return 0;
}