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

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));

        map<int, int> ma;
        forn(i, n) forn(j, m) cin >> v[i][j];
        forn(i, n){
            forn(j, m){
                int val = 0;
                if(i > 0 and v[i - 1][j] == v[i][j]) val = 1; 
                if(i < n - 1 and v[i + 1][j] == v[i][j]) val = 1; 
                if(j > 0 and v[i][j - 1] == v[i][j]) val = 1; 
                if(j < m - 1 and v[i][j + 1] == v[i][j]) val = 1; 

                ma[v[i][j]] = max(ma[v[i][j]], val);
            }
        }

        int rta = 0, maxi = 0;
        for(auto i : ma) {
            if(i.sc == 1) rta += 2;
            else rta += 1;
            maxi = max(maxi, i.sc + 1);
        }
        cout << rta - maxi << '\n';        
    }


    
    return 0;
}