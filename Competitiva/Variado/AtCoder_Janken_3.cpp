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

    int n; string s;
    cin >> n >> s;
    vector<vector<int>> dp(n + 1, vector<int>(3)); //dp[cuantas juegue][ult que elegi] = ganadas
    map<char, char> m{{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    vector<char> v{'R','P','S'};

    forr(i, 1, n + 1){
        forn(j, 3){
            bool gana = m[s[i - 1]] == v[j];
            if(m[v[j]] == s[i - 1]) continue; //Si usando esa no me gana
            forn(k, 3){ //Los que jugue antes
                if(j != k){ //Si no es la misma de antes
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + gana);
                }    
            }
        }
    }

    int ma = 0;
    forn(i, 3) ma = max(ma, dp[n][i]);
    cout << ma << '\n';
    
    return 0;
}