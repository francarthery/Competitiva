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

    int n;
    while(cin >> n and n){
        vector<vector<int>> v(n, vector<int>(n)), pref(n + 1, vector<int>(n)); 
        vector<vector<int>> dp(n, vector<int>(n));
        
        forn(i, n) forn(j, i + 1) cin >> v[i][j];
        forn(j, n) forn(i, n){
            pref[i + 1][j] = pref[i][j] + v[i][j];
        }
        

        
    }


    return 0;
}