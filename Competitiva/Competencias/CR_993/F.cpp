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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n, m, q, x;  
    cin >> n >> m >> q;

    vector<bool> a(2 * n + 1), b(2 * m + 1);
    ll sa = 0, sb = 0;

    forn(i, n){
        cin >> x;
        sa += x;
        a[x + n] = true;
    }

    forn(i, m){
        cin >> x;
        sb += x;
        b[x + m] = true;
    }

    auto rango = [&](ll a, ll b){
        return a >= 0 and a <= b;
    };
    
    forn(i, q){
        cin >> x;
        bool flag = false;

        for(ll j = 1; j * j <= abs(x); j++){
            if(x % j == 0){
                if(rango(sa - j + n, 2*n) and a[sa - j + n] and rango(sb - x / j + m, 2*m) and b[sb - x / j + m]) flag = true;
                else if(rango(sa - x / j + n, 2*n) and a[sa - x / j + n] and rango(sb - j + m, 2*m) and b[sb - j + m]) flag = true;
                else if(rango(sa + j + n, 2*n) and a[sa + j + n] and rango(sb + x / j + m, 2*m) and b[sb + x / j + m]) flag = true;
                else if(rango(sa + x / j + n, 2*n) and a[sa + x / j + n] and rango(sb + j + m, 2*m) and b[sb + j + m]) flag = true;
                if(flag) break;
            }    
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
    
    return 0;
}