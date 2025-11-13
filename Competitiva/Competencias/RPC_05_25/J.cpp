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
#define vdbg(x) {cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
ll MAX = 3 * 1e4 + 1;
int MOD = 1e9 + 7;
vector<vector<ll>> comb(MAX, vector<ll> (MAX));
void cargarComb() {  // O(MAXN^2)
    forn(i, MAX) {    // comb[i][k]=i tomados de a k = i!/(k!*(i-k)!)
      comb[0][i] = 0;
      comb[i][0] = comb[i][i] = 1;
      forr(k, 1, i) comb[i][k] = (comb[i - 1][k - 1] + comb[i - 1][k]) % MOD;
    }
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    cargarComb();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> m;
        forn(i,n){
            int x;
            cin >> x;
            m[x]++; 
        }
        int ma = INT_MIN;
        for(auto e: m){
            ma = max(e.second, ma);
        }
        cout << comb[n][ma] << '\n';

    }
    
    return 0;
}