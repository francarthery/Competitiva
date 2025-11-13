#include <bits/stdc++.h>

#define rec(i, a, b) for(int i=a; i<b; ++i)
#define rev(i, a, b) for(int i=b; i>=a; --i)

#define all(d) d.begin(), d.end()
#define rall(d) d.rbegin(), d.rend() 
#define tm(x) (int)x.size()

#define test freopen("input.in", "r", stdin);

#define nl cout<<"\n";
#define ws <<" "<<
#define bf cout << endl;
#define raya cout << "=====================";bf;
#define tiro 0
#define reci 1

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
typedef long double ld;

void solve(){
	int mu, ta, n;
	
	cin >> mu >> ta >> n;
	vector<stack<int>> yes(ta);
	vector<i64>car(ta);
	
	rec(i,0,n){
		int num, muel; cin >> muel >> num;
		--num;
		if(yes[num].empty()){
			yes[num].push(muel);
		} else {
			i64 ini = yes[num].top();
			yes[num].pop();
			i64 fin = muel;
			if(ini == fin) car[num]+=100LL;
			else car[num] += abs(ini-fin);
		}
	}
	rec(i,0,ta){
		if(yes[i].size()){
			car[i]+=100LL;
		}
	}
	cout << car[0];
	rec(i,1,ta) {
		cout << ' ' << car[i];
	}
	nl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	//test
	
	solve();

	return 0;
}

