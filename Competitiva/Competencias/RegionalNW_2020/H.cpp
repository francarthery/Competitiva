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

    int n;
    cin >> n;
    vector<int> v(n), res;
    forn(i, n) cin >> v[i];
    sort(all(v));

    if(n % 2){
        res.pb(v[n / 2]);
        forr(i, 1, n / 2 + 1){
            res.pb(v[n / 2 + i]);
            res.pb(v[n / 2 - i]);
        }
    }
    else{
        forn(i, n / 2){
            res.pb(v[n / 2 + i]);
            res.pb(v[n / 2 - i - 1]);
        }
    }

    
    int dif = -1;
    bool flag = true;
    forr(i, 1, n){
        if(abs(res[i - 1] - res[i]) < dif) flag = false;
        else dif = abs(res[i - 1] - res[i]);
    }

    if(flag) forn(i, n) cout << res[i] << ' ';
    else cout << "impossible\n";
    
    return 0;
}