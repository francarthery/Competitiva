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

    int n, k, q; cin >> n >> k;
    string s, pal; cin >> s;
    vector<vector<int>> let(k);
    forn(i, sz(s)){
        let[s[i] - 'a'].pb(i);
    }

    vector<int> dp(n + 1);
    dfor(i, n){
        int ma = 0;
        forn(j, k) {
            int ind = upper_bound(all(let[j]), i) - let[j].begin();
            if(ind == sz(let[j])) ma = n; //me sali del string
            else ma = max(ma, let[j][ind]);
        }
        dp[i] = dp[ma] + 1;
    }

    cin >> q;
    forn(t, q){
        cin >> pal;
        int ult = -1;
        bool flag = true;
        for(char &c : pal){
            ult = upper_bound(all(let[c - 'a']), ult) - let[c - 'a'].begin();
            if(ult == sz(let[c - 'a'])) {
                flag = false;
                break;
            }
            else ult = let[c - 'a'][ult];
        }

        cout << (flag ? dp[ult] : 0) << '\n';
    }

    return 0;
}