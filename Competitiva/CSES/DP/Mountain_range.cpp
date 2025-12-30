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

    int n; cin >> n;
    vector<int> dp(n + 2), v(n);
    vector<ii> ord(n);
    
    forn(i, n) {
        cin >> v[i];
        ord[i] = {v[i], i};
    }

    sort(rall(ord));
    vector<ii> st{{1e9, 0}};
    vector<int> izq(n), der(n);
    forn(i, n) {
        while(sz(st) and st.back().fr <= v[i]) st.pop_back(); 
        izq[i] = st.back().sc;
        st.push_back({v[i], i + 1});
    }
    st = vector<ii>{{1e9, n + 1}};
    dfor(i, n) {
        while(sz(st) and st.back().fr <= v[i]) st.pop_back(); 
        der[i] = st.back().sc;
        st.push_back({v[i], i + 1});
    }

    for(auto i : ord) dp[i.sc + 1] = max(dp[izq[i.sc]], dp[der[i.sc]]) + 1;

    cout << *max_element(all(dp)) << '\n';

    return 0;
}