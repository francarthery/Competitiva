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

	int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ii> v(n), v2;
        for(auto &[a, b] : v) cin >> a >> b;

        sort(all(v));
        int cont = 0;
        bool flag = 0;
        forn(i, n){
            if(i < n - 1 and v[i].fr == v[i + 1].fr){
                cont += n - 2;
                v2.pb({v[i].fr, 2});
                flag = 1;
            }
            else if(!flag) v2.pb(v[i]);
            else flag = 0;
        }

        //for(auto i : v2) cout << i.fr << ' ' << i.sc << '\n';

        forn(i, sz(v2) - 2){
            if(v2[i].fr == v2[i + 1].fr - 1 and v2[i].fr == v2[i + 2].fr - 2){
                cont += ((v2[i].sc == 2 or v2[i].sc == 1) and (v2[i + 2].sc == 2 or v2[i + 2].sc == 1) and (v2[i + 1].sc == 0 or v2[i + 1].sc == 2));
                cont += ((v2[i].sc == 2 or v2[i].sc == 0) and (v2[i + 2].sc == 2 or v2[i + 2].sc == 0) and (v2[i + 1].sc == 1 or v2[i + 1].sc == 2));
            }        
        }

        cout << cont << '\n';
    }

	return 0;
}