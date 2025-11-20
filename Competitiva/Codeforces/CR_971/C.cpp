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
		//freopen("output.out", "w", stdout);
	#endif

    int t, x, y, k;
    cin >> t;
    while(t--){
        cin >> x >> y >> k;
        int movx = (x + k - 1) / k, movy = (y + k - 1) / k;
        //dbg(movx); dbg(movy);
        if(movx > movy) cout << 2 * max(movx, movy) - 1 << '\n';
        else cout << 2 * max(movx, movy) << '\n';

    }

	return 0;
}

/*
3 0
3 3
6 3
6 6
9 6
9 9
9 9
9 11

*/