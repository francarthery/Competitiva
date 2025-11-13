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

vector<pair<int,int>> ans;

ll p0;

vector<ll> v;

void f(int i,int j){
	if(i == j){
		if(v[i-1] != 0){
			ans.pb({i,i});
			v[i-1] = 0;
		}
		return;
	}
	int tam = (j-i+1);
	
	if(v[j-1] == tam-1){
		f(i,j-1);
		return;
	}
	
	f(i,j-1);
	ans.pb({i,j});
	for(int k = i; k<=j; k++) v[k-1] = tam-1; 
	f(i,j-1);
}
		
		

int main() {

	freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	v.rsz(n);
	forn(i,n){
		cin>>v[i];
	}
	
	ll ans2 = 0;
	ll maskans = 0;
	forn(mask,(1<<n)){
		ll sum = 0;
		vector<int> vpos;
		forn(i,n){
			if(not ((1<<i) & mask)){
				if(sz(vpos)) sum += (vpos.back() - vpos[0] + 1LL) * (vpos.back() - vpos[0] + 1LL); 
				vpos.clear();
				sum+=v[i];
				continue;
			}
			vpos.pb(i);
		}
		if(sz(vpos)) sum += (vpos.back() - vpos[0] + 1LL) * (vpos.back() - vpos[0] + 1LL); 
		if(sum > ans2){
			ans2 = sum;
			maskans = mask;
		}
	}

	vector<int> vpos;
	forn(i,n){
		if(not ((1<<i) & maskans)){
			if(sz(vpos)) f(vpos[0]+1,vpos.back()+1);
			if(sz(vpos)) ans.pb({vpos[0]+1,vpos.back()+1});
			if(sz(vpos)) for(int j = vpos[0]; j<=vpos.back(); j++) v[j] = (vpos.back() - vpos[0] + 1);
			vpos.clear();
			continue;
		}
		vpos.pb(i);
	}
	
	if(sz(vpos)) f(vpos[0]+1,vpos.back()+1);
	if(sz(vpos)) ans.pb({vpos[0]+1,vpos.back()+1});
	if(sz(vpos)) for(int j = vpos[0]; j<=vpos.back(); j++) v[j] = (vpos.back() - vpos[0] + 1);
	
	
	ll sum = 0;
	forn(i,n) sum+=v[i];
	cout<<sum<<' '<<sz(ans)<<'\n';
	for(auto [a,b]: ans) cout<<a<<' '<<b<<'\n';
	
	return 0;
}
