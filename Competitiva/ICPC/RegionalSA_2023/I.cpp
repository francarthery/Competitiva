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
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s;
    ll n;
    cin >> s >> n;
    map<char, ll> m, m2;
    vector<ll> v(sz(s)), v2(sz(s));
    for(char &c : s) m[c]++;
    m2 = m;
    forn(i, sz(s)){
        m[s[i]]--;
        for(auto &j : m){
            if(j.fr < s[i]){
                v[i] += j.sc; 
                v[i] %= MOD;
            }
        }
    }
    dfor(i, sz(s)){
        m2[s[i]]--;
        for(auto &j : m2){
            if(j.fr < s[i]){
                v2[i] += j.sc; 
                v2[i] %= MOD;
            }
        }
    }
    //vdbg(v2); vdbg(v);
    __int128_t rta = 0, suma = (((__int128_t)n * (__int128_t)(n + 1)) / 2) % MOD, suma2 = (((__int128_t)n * (__int128_t)(n - 1)) / 2) % MOD;
    forn(i, sz(v)){
        rta = (rta + suma * v[i]) % MOD;
        rta = (rta + suma2 * v2[i]) % MOD;
    }

    ll ans = (ll)rta;
    cout << ans << '\n';
    
    return 0;
}