#include<bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define sz(a) ((int)(a.size()))
#define all(a) a.begin(), a.end()
#define dbg(x) cout << #x <<" "<< x << endl;
#define ws <<" "<<
#define nl cout << "\n";
typedef long long ll;

using namespace std;

int main(){

    #ifdef fran
        freopen("input.in", "r", stdin);
    #endif

    int n; cin >> n;
    vector<long long> v(n);
    forn(i, n) cin >> v[i];

    long double res = 0;
    ll sum = accumulate(all(v), 0ll), pref = 0;
    sort(v.rbegin(), v.rend());
    forn(i, n){
        pref += v[i];
        res = max(res, (long double)(pref) / (long double)(sum) - (long double)(i + 1) / (long double)(n));
    }

    cout << fixed << setprecision(15) << res * (long double)(100) << '\n';

    return 0;
}