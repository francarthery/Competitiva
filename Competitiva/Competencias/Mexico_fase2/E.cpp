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

    int n, x;
    cin >> n;
    vector<ii> v(n), g;
    forn(i, n) {
        cin >> x;
        v[i] = {x, i};
    }

    sort(all(v));
    int ini = 0;
    while(v[ini].fr == 1) ini++;

    bool flag = true;
    forr(i, ini, n){
        if(v[i].fr - 1 <= i){
            forn(j, v[i].fr - 1){
                g.pb({v[i].sc, v[j].sc});
            }
        }
        else {
            flag = false;
            break;
        }
    }

    if(!flag) cout << "-1\n";
    else{
        cout << sz(g) << '\n';
        forn(i, sz(g)) cout << g[i].fr + 1 << ' ' << g[i].sc + 1 << '\n';
    }

    
    return 0;
}