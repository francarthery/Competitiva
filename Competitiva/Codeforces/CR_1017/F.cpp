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

int n, m, k;

void paint(bool dir, vector<vector<int>> &v){
    int ini = 0;
    if(!dir){
        forn(i, n) forn(j, m){
            v[i][j] = ini + 1;
            ini = (ini + 1) % k;
        }
    }
    else{
        forn(j, m) forn(i, n){
            v[i][j] = ini + 1;
            ini = (ini + 1) % k;
        }
    }
}

void paint2(bool dir, vector<vector<int>> &v){
    if(dir){
        int ini = 0;
        forn(i, n) {
            int val = ini;
            forn(j, m){
                v[i][j] = val + 1;
                val = (val + 1) % k;
            }
            ini = (ini + 1) % k;
        }
    }
    else {
        int ini = 0;
        forn(j, m) {
            int val = ini;
            forn(i, n){
                v[i][j] = val + 1;
                val = (val + 1) % k;
            }
            ini = (ini + 1) % k;
        }
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        cin >> n >> m >> k;
        vector<vector<int>> ans(n, vector<int>(m));
        if((k <= n and n % k == 0)) paint2(0, ans); // 0 es pintar por filas
        else if(k <= m and m % k == 0) paint2(1, ans);
        else if(k > n and k % n == 0) paint(0, ans);
        else if(k > m and k % m == 0) paint(1, ans);
        else paint(0, ans);

        forn(i, n) {
            forn(j, m) cout << ans[i][j] << ' ';
            cout << '\n';
        }

    }



    return 0;
}