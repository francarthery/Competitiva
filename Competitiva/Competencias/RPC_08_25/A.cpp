#include <bits/stdc++.h>

#define rec(i, a, b) for(int i=a; i<b; ++i)
#define rev(i, a, b) for(int i=b; i>=a; --i)

#define printv(__cn) for(auto __el:__cn) cout << __el << ' ';
#define all(d) d.begin(), d.end()
#define rall(d) d.rbegin(), d.rend() 
#define tm(x) (int)x.size()

#define test freopen("input.in", "r", stdin);

#define nl cout<<"\n";
#define ws <<" "<<
#define bf cout << endl;
#define raya cout << "=====================";bf;

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
typedef long double ld;

void solve(){
	int n,b;
	cin >> n >> b;
	int ans = 0;
	if(n > b){
		rec(i,0,ceil((ld)n/2.0)) ans += b;
		cout << ans + ceil((ld)n/2.0);nl;
	}
	else {
		rev(i,floor((ld)n/2.0), n) ans += i;
		cout << ans + floor((ld)n/2.0);nl;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	//test
	
	solve();

	return 0;
}