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

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> v(n);
        vector<int> p(k);
        forn(i, n) cin >> v[i];
        forn(i, k) cin >> p[i], p[i]--;
        
        auto f = [&](int ind) {
            int ini = 0, fin = sz(v) - 1, flip = 0, ans = 0, orig = v[p[ind]];
            while(fin > ini) {
                while(v[ini] ^ flip == orig and ini < p[ind]) ini++;
                while(v[fin] ^ flip == orig and fin > p[ind]) fin--;
                if(ini != fin) flip ^= 1, ans++;
            }
            if(v[p[ind]] ^ flip != orig) ans++;
            return ans;
        };

        int resp = 1e9;
        forn(i, k) resp = min(resp, f(i));
        cout << resp << '\n';
    }



    return 0;
}