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

const int INF = 2e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m;
    string s1, s2;
    cin >> s1 >> s2;
    n = s1.size(); m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;
    forr(i, 1, n + 1) dp[i][0] = i; //Convierto el string s1[0, i] a vacio. i operaciones delete
    forr(i, 1, m + 1) dp[0][i] = i; //idem con s2

    forr(i, 1, n + 1){
        forr(j, 1, m + 1){ 
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1]; //Si son iguales no hago nada
            else dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}); //min(borrar, insertar, cambiar)
        }
    }

    cout << dp[n][m] << '\n';
    
    return 0;
}