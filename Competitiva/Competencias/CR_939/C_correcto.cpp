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
 
ll gauss(ll x){
	return x * (x+1) / 2;
}
 
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		
		int n;
		cin>>n;
	
		int pos = n+1;
		for(int i = 1; i<=n; i++){
			if(i*n >= gauss(n)){
				pos = i;
				break;
			}
		}
		//~ cout<<pos<<endl;
		ll ans[n][n];
		vector<vector<int>> vvans;
 
		for(int i = n-1; i>=0; i--){
			vvans.pb({});
			vvans.back().pb(1);
			vvans.back().pb(i+1);
			forn(j,n) vvans.back().pb(j+1), ans[i][j] = j+1;
			
			vvans.pb({});
			vvans.back().pb(2);
			vvans.back().pb(i+1);
			forn(j,n) vvans.back().pb(j+1), ans[j][i] = j+1;
 
		}
		
		ll sum = 0;
		forn(i,n) forn(j,n) sum+=ans[i][j];
	
		
		cout<<sum<<' '<<sz(vvans)<<'\n';
		for(auto v: vvans){
			for(auto e: v) cout<<e<<' ';
			cout<<'\n';
		}
	}
	
	
	
	return 0;
}