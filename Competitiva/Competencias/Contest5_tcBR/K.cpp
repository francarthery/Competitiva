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

const int a = 31, b = 1e9 + 7;
vector<ll> p, h;

void Hash(string &s){
    p.resize(s.size());
    h.resize(s.size());

    p[0] = 1;
    h[0] = s[0];
    for(int i = 1; i < s.size(); i++) {
        h[i] = (h[i - 1] * a + s[i]) % b;
        p[i] = (p[i - 1] * a) % b;
    }
}

ll gethash(int l, int r){
    if(l == 0) return h[r];
    else return ((h[r] - h[l - 1] * p[r - l + 1]) % b + b) % b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; string s;
    cin >> n >> s;
    Hash(s);
    vector<vector<int>> dp(n + 1, vector<int>(n, 1e9));

    forn(i, n) dp[1][i] = 1;

    forr(i, 2, n + 1) {
        forn(j, n - i + 1) {
            forr(k, 1, i) {
                int tam = dp[k][j] + dp[i - k][j + k];
                if(gethash(j, j+k-1) == gethash(j+k, j+i-1)) tam = dp[k][j];
                if(dp[i][j] > tam) dp[i][j] = tam;
            }
        }
    }

    cout << dp[n][0] << '\n';

    return 0;
}