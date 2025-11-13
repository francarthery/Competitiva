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

void merge(vector<int> &v, int l1, int m, int r2){
	
	vector<int> res;
	int it1 = l1, it2 = m;

	while(it1 < m and it2 < r2){
		if(v[it1] > v[it2]) res.pb(v[it2++]);
		else res.pb(v[it1++]);		
	}

	while(it1 < m) res.pb(v[it1++]);
	while(it2 < r2) res.pb(v[it2++]);

	forr(i, l1, r2) v[i] = res[i - l1];

}

void merge_sort(vector<int> &v, int l, int r){
	if(r - l <= 1) return;

	merge_sort(v, l, (l + r) / 2);
	merge_sort(v, (l + r) / 2, r);
	merge(v, l, (l + r) / 2, r);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifdef fran
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif

	vector<int> v{6, 93, 11, -1, 184, 0, 673, 837, 57, -835, 575};
	merge_sort(v, 0, 11);
	for(auto i : v) cout << i << ' ';
	cout << '\n';
	
	return 0;
}