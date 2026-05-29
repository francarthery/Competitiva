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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
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

	int k; cin >> k;
	vector<array<ll, 3>> v(k);
	forn(i, k) cin >> v[i][0] >> v[i][1] >> v[i][2];
	sort(all(v));

	int r; cin >> r;
	forn(tt, r) {
		ll tao, phi; cin >> tao >> phi;
		ll base = 0;
		vector<ll> c1(k), c2(k);
		forn(i, k) {
			c1[i] = c2[i] = v[i][1];
			base += v[i][1];
		}

		if(base > phi) {
			cout << "no\n";
			continue;
		}

		ll tot = base;
		forn(i, k) {
			c1[i] += min(phi - tot, v[i][2] - v[i][1]);
			tot += min(phi - tot, v[i][2] - v[i][1]);
		}
		tot = base;
		dfor(i, k) {
			c2[i] += min(phi - tot, v[i][2] - v[i][1]);
			tot += min(phi - tot, v[i][2] - v[i][1]);	
		}

		long double n1=0, n2=0, d1=0, d2=0;
		forn(i, k) {
			n1 += c1[i] * v[i][0];
			n2 += c2[i] * v[i][0];
			d1 += c1[i];
			d2 += c2[i];
		}

		if(tot == phi and tao >= n1/d1 and tao <= n2/d2) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}