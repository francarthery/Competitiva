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

    int n; cin >> n;
    vector<ll> x(n), r(n);
    map<ll, int> frec;
    forn(i, n) cin >> x[i];
    forn(i, n) {
        cin >> r[i];
        frec[r[i]]++;
    }

    if(n == 1) {
        cout << r[0] << '\n';
        return 0;
    }

    vector<ll> coef(n);
    ll mi = 1e18;
    ll ma = -1e18;
    forr(i, 1, n) {
        coef[i] = x[i]-x[i-1]-coef[i-1];
        if(i%2 == 0) mi = min(mi, coef[i]);
    }
    //dbg(mi);
    vector<ll> ans;
    for(auto i : frec) {
        ll prim = i.fr;
        if(prim < -mi) continue; //CUIDADO
        map<ll, int> uso;
        bool ok = true;
        dfor(j, n){
            if(j%2==0) {
                uso[coef[j] + prim]++;
                ans.pb(coef[j] + prim);
                if(uso[coef[j] + prim] > frec[coef[j] + prim]) {
                    ok = false;
                    break;
                }
            }
            else {
                uso[coef[j] - prim]++;
                ans.pb(coef[j] - prim);
                if(uso[coef[j] - prim] > frec[coef[j] - prim]) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) break;
        else ans.clear();
    }

    reverse(all(ans));
    for(ll i : ans) cout << i << ' ';
    cout << '\n';

    return 0;
}