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

    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        string s; cin >> s;
        vector<vector<ll>> v(n, vector<ll>(m));
        vector<ll> f(n), col(m), sf(n), sc(m);
        forn(i, n) forn(j, m) cin >> v[i][j];

        forn(i, n) forn(j, m) sf[i] += v[i][j];
        forn(j, m) forn(i, n) sc[j] += v[i][j];
        
        int i = 0, j = 0;
        f[i] = col[j] = 1;
        for(auto &c : s){
            if(c == 'D') i++;
            else j++;

            f[i]++; 
            col[j]++;
        }


        i = 0, j = 0;
        for(auto &c : s){
            if(f[i] == 1){
                v[i][j] = -sf[i];
                sc[j] -= sf[i];
            }
            else{
                v[i][j] = -sc[j];
                sf[i] -= sc[j];
            }
            f[i]--;
            col[j]--;

            if(c == 'D') i++;
            else j++;
        }
        v[n - 1][m - 1] = -sc[m - 1];

        forn(i, n){
            forn(j, m) cout << v[i][j] << ' ';
            cout << '\n';
        }

    }
    
    return 0;
}