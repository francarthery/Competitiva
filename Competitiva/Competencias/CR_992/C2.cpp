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

ll exponente(int n){
    if(n > 41) return 1e13;
    else return (1ll << n);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;

        if(n < 41 and k > (1ll << (n - 1))){
            cout << -1 << '\n';
            continue;
        }

        vector<int> v(n);
        ll l = 0, r = n - 1, p = 0;
        forn(i, n){
            if(p + exponente(n - i - 2) < k){
                p += exponente(n - i - 2);
                v[r--] = i + 1;
            }
            else v[l++] = i + 1;
        }
        forn(i, n) cout << v[i] << ' ';
        cout << '\n';
    }


    
    return 0;
}