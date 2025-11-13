#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
	cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifdef fran
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	
	int n, x, y, clock = 0, ant = 0;
	prq<ii> pq;
	cin >> n;
	vector<ii> pos;
	vector<ii> v(n);
	forn(i, n){
		cin >> x >> y;
		v[i] = {x, y};
	}
	reverse(all(v));
	int ind = 0;
	while(!v.empty()){
		while(!pq.empty() and v.back().fr > clock){
			pos.pb({pq.top().sc, clock++});
			pq.pop();
		}
		clock = v.back().fr; //Si me sigue sobrando tiempo y se vacio la cola actualizo clock

		while(!v.empty() and v.back().fr <= clock){
			pq.push({v.back().sc - v.back().fr, ind++});
			v.pop_back();
		}
	}

	while(!pq.empty()){
		pos.pb({pq.top().sc, clock++});
		pq.pop();
	}

	sort(all(pos));
	forn(i, pos.size()) cout << pos[i].sc << ' ';
	cout << '\n';

	return 0;
}
