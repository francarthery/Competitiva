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

    int tt; cin >> tt;
    const ll MOD = 676767677; //lcdsm
    while(tt--) {
        int n, m; cin >> n >> m;
        vector<int> v(n); 
        forn(i, n) cin >> v[i];

        bool ok = true;
        forn(i, n) {
            if(v[i] != 0 and (i == 0 or v[i-1] >= v[i]) and (i == n-1 or v[i+1] >= v[i])) ok = false;
        }
        if(!ok) {
            cout << 0 << '\n';
            continue;
        }

        int sit = 0;
        vector<vector<ii>> nums(m+1); //tiempo, (pos, t_desbloqueo)
        vector<bool> unlock(n);
        forn(i, n) if(!v[i]) {
            nums[0].pb({i, 0});
            unlock[i] = true;
        }

        ll ans = 1, ant = 0;
        forn(t, m+1) {
            for(auto i : nums[t]) {
                if(i.sc == t - 1) ans = (ans * sit) % MOD;
                else if(ant) ans = (ans * ant) % MOD;

                if(i.fr > 0 and !unlock[i.fr - 1]) {
                    nums[v[i.fr - 1]].pb({i.fr - 1, t});
                    unlock[i.fr - 1] = true;
                }
                if(i.fr < n-1 and !unlock[i.fr + 1]){
                    nums[v[i.fr + 1]].pb({i.fr + 1, t});
                    unlock[i.fr + 1] = true;
                }
            }
            ant = sz(nums[t]);
            sit += ant;
        }

        cout << ans << '\n';
    }


    return 0;
}