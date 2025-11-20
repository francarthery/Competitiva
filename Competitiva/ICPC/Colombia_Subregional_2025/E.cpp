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
    vector<ii> v(n);
    forn(i, n) cin >> v[i].fr;
    forn(i, n) cin >> v[i].sc;
    vector<int> menor(n);

    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() and v[st.top()] >= v[i]) st.pop();
        menor[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    int cont = 0;
    vector<int> ans;
    forn(i, n){
        if(menor[i] == -1)ans.pb(i + 1);
        else if(v[menor[i]].sc < v[i].sc) ans.pb(i + 1);
    }

    cout << sz(ans) << '\n';
    for(auto e : ans) cout << e << ' ';


    return 0;
}