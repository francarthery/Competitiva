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

typedef long double T; // double could be faster but less precise
typedef long double ld;

const ld pi = acosl(-1);
const T INF = 1e18;
struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
	T operator*(pto b) { return x*b.x + y*b.y; }
	T operator^(pto b) { return x*b.y - y*b.x; }
};
ld angle(pto a, pto o, pto b) {
	pto oa = a-o, ob = b-o;
	return atan2l(oa^ob, oa*ob);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<pair<pto, int>> v(n);
    forn(i, n) cin >> v[i].fr.x >> v[i].fr.y >> v[i].sc;
    ll mi = 1e18;

    forn(orig, n) {
        vector<pair<ld, int>> al;
        int ref = (orig ? 0 : 1);

        ll s = 0, b = 0, ptr = 0;
        forn(i, n) {
            if(i == orig) continue;

            ld theta = angle(v[ref].fr, v[orig].fr, v[i].fr);
            if(theta < 0) theta = 2*pi + theta;
            al.pb({theta, v[i].sc});
            al.pb({theta + 2*pi, v[i].sc}); 
            b += v[i].sc;
        }
        sort(all(al));

        forn(i, sz(al)) {
            if(al[i].fr >= 2*pi) break;
            s -= al[i].sc;

            while(ptr < sz(al) and al[ptr].fr < al[i].fr + pi) {
                b -= al[ptr].sc;
                s += al[ptr].sc;
                ptr++;
            }
            mi = min(mi, abs(s - b));
            b += al[i].sc;
        }
    }

    cout << mi << '\n';

    return 0;
}