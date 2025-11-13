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

    int t, n, m, x;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<ii> v;
        forn(i, n) {
            forn(j, m){
                cin >> x;
                v.pb({x, i});
            }
        }

        bool flag = true;
        sort(all(v));
        forr(i, 1, m){
            forn(j, n){
                if(v[i * n + j].sc != v[j].sc) flag = false;
            }
        }

        if(flag){
            forn(i, n) cout << v[i].sc + 1 << ' ';
            cout << '\n';
        }
        else cout << -1 << '\n';
    }


    
    return 0;
}