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

int INF = (int)2e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(10, INF));

    forn(i, 10) dp[0][i] = 0;
    forr(i, 1, n + 1){
        set<int> s;
        int aux = i;
        while(aux > 0){ //Miro los digitos que tiene el numero
            s.insert(aux % 10);
            aux /= 10;
        }
        for(int j : s){
            forn(k, 10){
                if(i >= j) dp[i][j] = min(dp[i][j], dp[i - j][k] + 1);
            }
        }
    }

    int mi = INF;
    forn(i, 10) mi = min(mi, dp[n][i]);
    cout << mi << '\n';
    
    return 0;
}