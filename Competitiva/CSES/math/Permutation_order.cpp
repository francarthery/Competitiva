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

    vector<ll> fact(21);
    fact[0] = 1;
    forr(i, 1, 21) fact[i] = fact[i - 1] * i;

    auto perm = [&](int n, ll k){ //Genera permutacion k de tam n en n^2.
        vector<int> v;
        set<int> s;
        forn(i, n) s.insert(i + 1);
        k--;
        
        ll total = fact[n];
        forn(i, n){
            ll pos = k / (total / (n - i));
            auto it = s.begin();
            forn(j, pos) it++;
            v.pb(*it);
            s.erase(it);

            total /= (n - i);
            k -= pos * total;
        }
        
        return v;
    };
    
    int t; cin >> t;
    while(t--){
        ll x, n, k;
        cin >> x >> n;
        if(x == 1){
            cin >> k;
            vector<int> v = perm(n, k);
            for(int i : v) cout << i << ' ';
            cout << '\n';
        }
        else{
            vector<int> v(n);
            forn(i, n) cin >> v[i];

            ll l = 0, r = fact[n] + 1;
            while(r - l > 1){
                ll m = (r + l) / 2;
                vector<int> aux = perm(n, m);
                if(aux > v) r = m;
                else l = m;
            }

            cout << l << '\n';
        }

    }



    return 0;
}