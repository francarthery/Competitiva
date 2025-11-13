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

const int MOD = 998244353;

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
        int n, x;
        cin >> n;

        unordered_map<int, ll> ultx, ult;
        
        cin >> x;
        ultx[1] = 1; // mintio una vez en la anterior
        if(x == 0) ult[0] = 1; //No mintio nunca

        forr(i, 1, n){
            cin >> x;
            unordered_map<int, ll> ultx2, ult2;
            ult2[x] = (ultx[x] + ult[x]) % MOD; //No menti

            for(auto u : ult){
                ultx2[u.fr + 1] = u.sc; //Miento 
            }
            ultx = ultx2;
            ult = ult2;
        }

        ll sum = 0;
        for(auto i : ultx) sum = (sum + i.sc) % MOD;
        for(auto i : ult) sum = (sum + i.sc) % MOD;
        cout << sum << '\n';
    }
    
    return 0;
}