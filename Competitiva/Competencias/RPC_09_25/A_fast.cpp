#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) forr(i,0,n)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define ws <<' '<<
#define nl cout << '\n';

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

    int n, m, r, c; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    forn(i, n) forn(j, m) cin >> v[i][j];
    cin >> r >> c;

    forn(i, n){
        deque<ii> q;
        dfor(j, m) {
            while(sz(q) and q.back().first <= v[i][j]) q.pop_back();
            if(sz(q) and q.front().second >= j + c) q.pop_front();
            q.push_back({v[i][j], j});
            v[i][j] = q.front().first;
        }
    }

    forn(j, m - c + 1){
        deque<ii> q;
        dfor(i, n) {
            while(sz(q) and q.back().first <= v[i][j]) q.pop_back();
            if(sz(q) and q.front().second >= i + r) q.pop_front();
            q.push_back({v[i][j], i});
            v[i][j] = q.front().first; 
        }
    }

    forn(i, n - r + 1) forn(j, m - c + 1) cout << v[i][j] << (j == m - c ? '\n' : ' ');

	return 0;
}