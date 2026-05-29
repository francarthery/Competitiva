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

    string s, t; cin >> s >> t;
    map<char, vector<int>> m;
    forn(i, sz(s)) {
        m[s[i]].pb(i);
    }

    int pos = -1, ans = 1;
    forn(i, sz(t)) {
        auto ind = upper_bound(all(m[t[i]]), pos) - m[t[i]].begin();
        if(ind == sz(m[t[i]])) {
            ans++;
            pos = -1;
            i--;
        }
        else pos = m[t[i]][ind];
    }

    cout << ans << '\n';

    return 0;
}