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
typedef pair<int, char> ic;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int r, g, b; cin >> r >> g >> b;
        vector<ic> let{{r, 'R'}, {g, 'G'}, {b, 'B'}};
        sort(rall(let));

        string ans;
        while(let[1].fr + let[2].fr > let[0].fr) {
            ans += let[2].sc;
            ans += let[1].sc;
            let[1].fr--;
            let[2].fr--;
        }

        forn(i, let[1].fr) {
            ans += let[0].sc;
            ans += let[1].sc;
            let[0].fr--;    
        }
        forn(i, let[2].fr) {
            ans += let[0].sc;
            ans += let[2].sc;
            let[0].fr--;
        }
        if(let[0].fr) ans += let[0].sc;

        cout << ans << '\n';
    }



    return 0;
}