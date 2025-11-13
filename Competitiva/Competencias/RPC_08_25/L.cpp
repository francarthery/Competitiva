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
#define tiro 0
#define reci 1

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
typedef long double ld;

void solve(){
	int r[2][3];
	rec(j,0,2) rec(i,0,3) cin >> r[j][i];
	set<vector<int>> ev;
	//0 es puede disp, 1 es recibe
	//0 tiempo 1 tipo 2 actor
	ev.insert({0,0,0});
	ev.insert({0,0,1});
	while(true){
		vector<int> v = *ev.begin();
		ev.erase(ev.begin());
		int actor = v[2];
		int time = v[0];
		
		if(v[1] == reci){
			r[actor][0]-=r[!actor][1];
			if(r[actor][0]<=0){
				bool flag = 1;
				while((*ev.begin())[0] == time){
					vector<int> nxt = *ev.begin();
					ev.erase(ev.begin());
					if(nxt[2] == actor) continue;
					if(nxt[1] != reci) continue;
					int now = nxt[2];
					r[now][0]-=r[!now][1];
					if(r[0][0] <= 0 && r[1][0] <= 0){
						cout << "draw";nl;
						flag = 0;
						return;
					}
				}
				if(flag){
					cout << "player ";
					cout << (actor == 0 ? "two" : "one");nl;
					return;
				}
			}
		} else {
			if(r[actor][0] > 0){
				ev.insert({time+1, reci, !actor});
				ev.insert({time+r[actor][2]*2, tiro, actor});
			}
		}
	
		
	
	}
	
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	//test
	
	solve();

	return 0;
}
