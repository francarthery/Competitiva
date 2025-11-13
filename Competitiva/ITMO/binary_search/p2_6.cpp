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

    string t, p;
    cin >> t >> p;
    vector<int> v(sz(t));
    forn(i, sz(t)) cin >> v[i];

    int l = -1, r = sz(t);
    while(r - l > 1){
        int m = (l + r) / 2;
        string aux = t, ans;
        forn(i, m) aux[v[i] - 1] = '#';
        forn(i, sz(t)) if(aux[i] != '#') ans.pb(aux[i]);

        //dbg(m); dbg(ans);
        int j = 0;
        bool flag = false;
        forn(i, sz(ans)) if(!flag and ans[i] == p[j]){
            j++;
            if(j == sz(p)) flag = true;
        }

        if(flag) l = m;
        else r = m;
    }

    cout << l << '\n';
    
    return 0;
}