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

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        set<int> s, usados;
        forn(i, n){
            int x; cin >> x;
            s.insert(x);
        }

        bool flag = true;
        vector<int> ans;
        while(flag and sz(s)){
            int mi = *s.begin();
            s.erase(*s.begin());
            
            if(usados.count(mi)) continue;
            ans.pb(mi);

            for(int i = 2 * mi; i <= k; i += mi){
                if(!s.count(i)) {
                    flag = false;
                    break;
                }
                usados.insert(i);
            }
        }

        if(flag) {
            cout << sz(ans) << '\n';
            for(int i : ans) cout << i << ' ';
            cout << '\n';
        }
        else cout << -1 << '\n';
    }



    return 0;
}