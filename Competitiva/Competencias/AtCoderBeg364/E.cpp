#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, x, y, a, b;
    cin >> n >> x >> y >> a >> b;
    vector dp(n + 1, vector(n + 1, vector(x + 1, 1e9))); //dp[indice_max][cant_platos][sweetnes] = minima cant de saltines

    dp[0][0][0] = 0;
    forn(i, n){
        cin >> a >> b;
        forn(j, i + 1){
            forn(k, x + 1){
                //dp[i][j][k]
            }
        }
    }
    
    return 0;
}