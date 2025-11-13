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

typedef long double T; // double could be faster but less precise
typedef long double ld;
const T EPS = 1e-9; // if T is integer, set to 0
const T INF = 1e18;
struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
	pto operator+(pto b) { return pto(x+b.x, y+b.y); }
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
	pto operator*(T k) { return pto(x*k, y*k); }
	T operator*(pto b) { return x*b.x + y*b.y; }
	T norm_sq() { return x*x + y*y; }
};

struct line {
  T a, b, c;  // Ax+By=C
  line() {}
};

#define sqr(a) ((a)*(a))
struct circle{
	pto o; T r;
    circle() {}
	circle(pto O, T R) : o(O), r(R) {}

	bool inside(pto p) { return (o-p).norm_sq() <= r*r+EPS; }

	vector<pto> inter(line l) {
		ld a = l.a, b = l.b, c = l.c - l.a*o.x - l.b*o.y;
		pto xy0 = pto(a*c/(a*a + b*b), b*c/(a*a + b*b));
		if(c*c > r*r*(a*a + b*b) + EPS) {
			return {};
		}else if(abs(c*c - r*r*(a*a + b*b)) < EPS) {
			return { xy0 + o };
		}else{
			ld m = sqrtl((r*r - c*c/(a*a + b*b))/(a*a + b*b));
			pto p1 = xy0 + (pto(-b,a)*m);
			pto p2 = xy0 + (pto(b,-a)*m);
			return { p1 + o, p2 + o };
		}
	}
	vector<pto> inter(circle c) {
		line l;
		l.a = o.x - c.o.x;
		l.b = o.y - c.o.y;
		l.c = (sqr(c.r)-sqr(r)+sqr(o.x)-sqr(c.o.x)+sqr(o.y)-sqr(c.o.y))/2.0;
		return (*this).inter(l);
	}
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    while(cin >> n){
        int x, y, r;
        vector<circle> v(n);
        vector<pto> inter;

        forn(i, n){
            cin >> x >> y >> r;
            v[i] = circle(pto(x, y), r);
            inter.pb(pto(x, y)); //meto centros
            //assert(v[i].o == pto(x, y));
        }

        forn(i, n){
            forn(j, n){
                vector<pto> aux = v[i].inter(v[j]); 
                for(auto &k : aux) inter.pb(k); //todas las posibles intersecciones
            }
        }

        ll ma = 0;
        for(auto &i : inter){
            int cont = 0;
            forn(j, n) if(v[j].inside(i)) cont++;
            ma = max(ma, (ll)cont);
        }

        cout << ma << '\n';
    }
    
    return 0;
}