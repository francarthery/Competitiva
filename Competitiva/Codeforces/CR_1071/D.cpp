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
        int n; cin >> n;
        set<int> s;
        forn(i, (1 << n)) s.insert(i);

        int mask = (1 << 16) - 1;

        vector<vector<int>> v(16);
        dfor(b, 16) {
            forn(i, (1 << n)) {
                if(s.count(i) and (i & mask) == mask) {
                    v[b].pb(i);
                    s.erase(i);
                }
            }
            mask ^= (1 << b); 
        }

        dfor(i, 16){
            for(int j : v[i]) cout << j << ' ';
        }
        for(int i : s) cout << i << ' ';
        cout << '\n';
    }



    return 0;
}