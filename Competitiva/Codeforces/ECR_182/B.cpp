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
        vector<int> v(n);
        forn(i, n) cin >> v[i];

        int ma = 0;
        set<int> faltan;
        forn(i, n) faltan.insert(i + 1);

        int l = n, r = 0;
        forn(i, n){
            if(v[i] != 0){ 
                faltan.erase(v[i]);
                if(abs((i + 1) - v[i])) {
                    l = min(l, i + 1);
                    r = max(r, i + 1);
                }
            }
        }

        if(sz(faltan)) forn(i, n){
            if(v[i] == 0){
                if(sz(faltan) == 1 and *faltan.begin() == i + 1) continue;
                l = min(l, i + 1);
                r = max(r, i + 1);
            }
        }

        if(l == n and r == 0) cout << 0 << '\n';
        else cout << r - l + 1 << '\n';
    }



    return 0;
}