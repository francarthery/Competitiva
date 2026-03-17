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
const T EPS = 1e-9; // if T is integer, set to 0
const T INF = 1e18;
const T pi = acosl(-1);
struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
	pto operator+(pto b) { return pto(x+b.x, y+b.y); }
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
	pto operator+(T k) { return pto(x+k, y+k); }
	pto operator*(T k) { return pto(x*k, y*k); }
	pto operator/(T k) { return pto(x/k, y/k); }
	// dot product
	T operator*(pto b) { return x*b.x + y*b.y; }
	// module of cross product, a^b>0 if angle_cw(u,v)<180
	T operator^(pto b) { return x*b.y - y*b.x; }
	// vector projection of this above b
	pto proj(pto b) { return b*((*this)*b) / (b*b); }
	T norm_sq() { return x*x + y*y; }
	ld norm() { return sqrtl(x*x + y*y); }
	ld dist(pto b) { return (b - (*this)).norm(); }
	//rotate by theta rads CCW w.r.t. origin (0,0)
	pto rotate(T ang) {
		return pto(x*cosl(ang) - y*sinl(ang), x*sinl(ang) + y*cosl(ang));
	}
	// true if this is at the left side of line ab
	bool left(pto a, pto b) { return ((a-*this) ^ (b-*this)) > 0; }
	bool operator<(const pto &b) const {
		return x < b.x-EPS || (abs(x - b.x) <= EPS && y < b.y-EPS);
	}
	bool operator==(pto b){ return abs(x-b.x)<=EPS && abs(y-b.y)<=EPS; }
};
ld angle(pto a, pto o, pto b) {
	pto oa = a-o, ob = b-o;
	return atan2l(oa^ob, oa*ob);
}
ld angle(pto a, pto b) { // smallest angle bewteen a and b
	ld cost = (a*b) / a.norm() / b.norm();
	return acosl(max(ld(-1.), min(ld(1.), cost)));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    vector<vector<bool>> pts(201, vector<bool>(201));
    int n; cin >> n;
    vector<pto> v(n);
    int a, b;
    forn(i, n) {
        cin >> a >> b; a+=100; b+=100;
        v[i] = pto(a, b);
        pts[a][b] = true;
    }

    ll ans = 0;
    vector<T> seg = {v[0].dist(v[1]), v[1].dist(v[2]), v[2].dist(v[0])};
    vector<T> angint = {angle(v[1], v[0], v[2]), angle(v[2], v[1], v[0]), angle(v[0], v[2], v[1])};
    vector<T> angext = {angle(v[1]-v[0], pto(0,0), pto(1, 0)),
                        angle(v[2]-v[1], pto(0,0), pto(1, 0)),
                        angle(v[0]-v[2], pto(0,0), pto(1, 0))}; //Dudoso
    vector<T> lado = {v[0].dist(v[2]), v[1].dist(v[0]), v[2].dist(v[1])};
    
    forn(i, n) forr(j, i+1, n) {
        T largo = v[i].dist(v[j]);
        forn(k, 3){
            T factor = largo / seg[k];
            pto tercer = pto(1, 0); //Creo un vector de 1 de largo
            tercer = tercer.rotate(angext[k] - angint[k]); //Lo roto correctamente
            tercer = tercer * lado[k] * factor; //Lo ubico y escalo donde va
            tercer = tercer + v[k];

            if(abs(tercer.x - round(tercer.x)) < 1e-4 and abs(tercer.y - round(tercer.y)) < 1e-4) {
                if(tercer.x <= 200 and tercer.y <= 200) ans += pts[tercer.x][tercer.y];
            }

            tercer = pto(1, 0);
            tercer = tercer.rotate(angext[k] - 2*pi + angint[k]); //Pruebo si el punto esta del otro lado
            tercer = tercer * lado[k] * factor; //Lo ubico y escalo donde va
            tercer = tercer + v[k];
            if(abs(tercer.x - round(tercer.x)) < 1e-4 and abs(tercer.y - round(tercer.y)) < 1e-4) {
                if(tercer.x <= 200 and tercer.y <= 200) ans += pts[tercer.x][tercer.y];
            }
        }    
    }

    cout << ans << '\n'; //dividir por 3 probablemente.


    return 0;
}