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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifdef fran
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif

	int n, m;
	while(cin >> n >> m and (n or m)){
		vector<vector<int>> v(n, vector<int>(m)), crec(n, vector<int>(m, 1));
		forn(i, n) forn(j, m) cin >> v[i][j];
		forn(i, n) dfor(j, m - 1){
			if(v[i][j + 1] > v[i][j]) crec[i][j] = crec[i][j + 1] + 1;
		}

		int ma = 0;

		forn(j, m){ //Recorro columnas
			int tam = crec[0][j];
			vector<ii> st{{tam, 0}};
			forr(i, 1, n){
				int ind = lower_bound(v[i - 1].begin() + j, v[i - 1].begin() + j + tam, v[i][j]) - v[i - 1].begin();
				int val = min(crec[i][j], ind - j);

				while(!st.empty() and val < st.back().fr){
					ma = max(ma, (i - st.back().sc) * st.back().fr);
					ind = st.back().sc;
					st.pop_back();					
				}

				if(val > 0 and (st.empty() or val > st.back().fr)) st.pb({val, ind});

				tam = crec[i][j];
				if(st.empty() or tam > st.back().fr) st.pb({tam, i});
			}

			while(!st.empty()){
				ma = max(ma, (n - st.back().sc) * st.back().fr);
				st.pop_back();
			}
		}

		cout << ma << '\n';
	}


	
	return 0;
}