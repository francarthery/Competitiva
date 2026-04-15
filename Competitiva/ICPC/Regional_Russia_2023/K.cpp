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

typedef long double ld;
ld pi = acos(-1);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ld a, b, c, d; cin >> a >> b >> c >> d;

    if(a < b) swap(a, b);
    if(c < d) swap(c, d);

    if(b < d) {
        cout << "NO\n";
        return 0;
    }

    auto f = [&](ld theta) {
        ld w = sinl(theta) * d;
        ld h = cosl(theta) * d;
        ld up = (b - h) / sinl(theta);
        ld down = (a - w) / cosl(theta);
        return min(up, down);
    };

    ld l = 0, r = pi/3;

    ld ma = 0;
    forn(i, 5000000) { //Terrible que ande
        ma = max(ma, f(((ld)(i)/100) * r));
    }

    cout << (ma >= c ? "YES" : "NO") << '\n';


    return 0;
}