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
typedef pair<int, double> iid;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifdef fran
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
    
    double ang, res = 0;
    int a, b, n;
    cin >> ang >> n;
    ang = (ang * 2 * acos(-1)) / 360;
    vector<iid> v(n);
    forn(i, n){
        cin >> a >> b;
        v[i] = {a, a + b / tan(ang)};
    }

    sort(all(v));
    iid inter = v[0];
    forr(i, 1, n){
        if(inter.sc > v[i].fr and inter.sc < v[i].sc) inter.sc = v[i].sc;
        else if(inter.sc < v[i].fr) {
            res += inter.sc - inter.fr;
            inter = v[i];
        }
    }
    res += inter.sc - inter.fr;

    cout << fixed << setprecision(6) << res << '\n';

	return 0;
}