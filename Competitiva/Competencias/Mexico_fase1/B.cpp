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

void f(vector<vector<int>> &m, vector<int> &v){
    int n = sz(m), dir = 0;
    vector<vector<bool>> vis(n, vector<bool>(n));
    ii pos = {0, 0};
    while(!vis[pos.fr][pos.sc]){
        if(dir == 0){
            while(pos.fr < n and !vis[pos.fr][pos.sc]) {
                v.pb(m[pos.fr][pos.sc]);
                vis[pos.fr][pos.sc] = true;
                pos.fr++;
            }
            pos.fr--; pos.sc++;
        }
        else if(dir == 1){
            while(pos.sc < n and !vis[pos.fr][pos.sc]) {
                v.pb(m[pos.fr][pos.sc]);
                vis[pos.fr][pos.sc] = true;
                pos.sc++;
            }
            pos.sc--; pos.fr--;
        }
        else if(dir == 2){
            while(pos.fr >= 0 and !vis[pos.fr][pos.sc]) {
                v.pb(m[pos.fr][pos.sc]);
                vis[pos.fr][pos.sc] = true;
                pos.fr--;
            }
            pos.fr++; pos.sc--;
        }
        else{
            while(pos.sc >= 0 and !vis[pos.fr][pos.sc]) {
                v.pb(m[pos.fr][pos.sc]);
                vis[pos.fr][pos.sc] = true;
                pos.sc--;
            }
            pos.fr++; pos.sc++;
        }
        dir = (dir + 1) % 4;
    }
}

void invh(vector<vector<int>> &m){
    forn(i, sz(m)){
        forn(j, sz(m) / 2) swap(m[i][j], m[i][sz(m) - 1 - j]);
    }
}

void invv(vector<vector<int>> &m){
    forn(i, sz(m)){
        forn(j, sz(m) / 2) swap(m[j][i], m[sz(m) - 1 - j][i]);
    }
}

void ref(vector<vector<int>> &m){
    forn(i, sz(m)){
        forn(j, i) swap(m[i][j], m[j][i]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    forn(i, n) forn(j, n) cin >> m[i][j];

    if(n == 1){
        cout << max(0, m[0][0]) << '\n';
        return 0;
    }


    ll rta = 0;
    forn(i, 8){
        if(i & (1 << 2)) invv(m);
        if(i & (1 << 1)) invh(m);
        if(i & 1) ref(m);

        vector<int> v;
        f(m, v);
        ll ans = v[0];
        ll maxi = v[0];

        forr(i, 1, sz(v)){
            maxi = max(maxi + v[i], (ll)v[i]); //si lo que tenias acumulado es menor a tu actual, soltalo rey
            ans = max(ans, maxi);
        }
        
        rta = max(rta, ans);

        if(i & (1 << 2)) invv(m);
        if(i & (1 << 1)) invh(m);
        if(i & 1) ref(m);
    }

    cout << rta << '\n';



    return 0;
}