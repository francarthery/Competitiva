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
const ld pi = acosl(-1);

struct pto{
    ll x, y, z=0;
    pto operator-(pto b) { return pto(x-b.x, y-b.y, z-b.z); }
    pto operator^(pto b) {
        pto res;
        res.x = y*b.z - z*b.y;
        res.y = z*b.x - x*b.z;
        res.z = x*b.y - y*b.x;
        return res;
    }
    ld operator*(pto b) {return (x*b.x + y*b.y + z*b.z);}
    ld norm() {return sqrtl(x*x + y*y + z*z);}
};

ld angle(pto a, pto b) {
    return atan2l((a^b).norm(), a * b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    pto ape, sun;
    cin >> ape.x >> ape.y >> ape.z;
    cin >> sun.x >> sun.y >> sun.z;

    vector<pto> v(n+1);
    forn(i, n) cin >> v[i].x >> v[i].y;
    v[n] = v[0];

    bool ok = false;
    forn(i, n) {
        pto ap1 = v[i] - ape;
        pto ap2 = v[i+1] - ape;
        pto normal = ap2 ^ ap1; 

        //pruebo los dos por si alguno es paralelo al otro
        if(angle(normal, sun - v[i])*2 > pi or angle(normal, sun - ape)*2 > pi) ok = true;
    }

    cout << (ok ? "S" : "N") << '\n';

    return 0;
}