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
#define sqr(a) ((a) * (a))

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

    int n, x, y, h;
    cin >> n;
    vector<ii> c(n);
    vector<int> r(n);
    forn(i, n){
        cin >> x >> y >> h;
        c[i] = {x, y};
        r[i] = h;
    }

    forn(i, n){
        ll rta = r[i];
        forn(j, n){
            if(i == j) continue;
            if(r[i] <= r[j]) rta = min(rta, (ll)sqrtl(sqr(c[i].fr - c[j].fr) + sqr(c[i].sc - c[j].sc)));
        }
        cout << rta << '\n';
    }

    
    return 0;
}