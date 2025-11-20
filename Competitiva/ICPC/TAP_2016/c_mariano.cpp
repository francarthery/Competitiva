#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef NANO
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
int n,m;
vector<vector<int>> g;
vector<int> v,vdin,vdinnow,vpainted,vdone;

int ans = 0;

void go(int x){
	ans++;
	vdone[x] = 1;
	for(auto e: g[x]) vdinnow[e]++;
	for(auto e: g[x]) if(vdin[e] == vdinnow[e] and vpainted[e] and not vdone[e]) go(e); 
}

void paint(int x){
	vpainted[x] = 1;
	if(vdin[x] == vdinnow[x] and not vdone[x]) go(x); 
}

int main() {
	#ifdef fran
		freopen("input.in", "r", stdin);
		freopen("output.out","w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	g.rsz(n);
	vdin.assign(n,0);
	vdinnow.assign(n,0);
	v.rsz(n);
	vpainted.assign(n,0);
	vdone.assign(n,0);
	
	forn(i,m){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].pb(b);
		vdin[b]++;
	}
	forn(i,n) cin>>v[i],v[i]--;
	for(auto e: v){
		paint(e);
		cout<<ans<<'\n';
	}
	
	return 0;
}
