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
typedef long double ld;

const int MAX = 1e5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ld c; cin >> c;

    ll lim = log2l(MAX / 1e-6) + 30; //hacer iteraciones hasta como minimo log(maxans / eps)

    ld l = 0, r = MAX;
    forn(t, lim){
        ld m = (r + l) / 2.0;
        if(m * m + sqrtl(m) >= c) r = m;
        else l = m;
    }
    
    cout << fixed << setprecision(8) << l << '\n';

    return 0;
}