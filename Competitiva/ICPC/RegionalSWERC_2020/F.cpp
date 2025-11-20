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
#define vdbg(x) {cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second
#define buenas(P) (P.y < 0 || (P.y == 0 && P.x < 0)) // True if angle >=180

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
	pto operator+(T k) { return pto(x+k, y+k); }
	pto operator*(T k) { return pto(x*k, y*k); }
	pto operator/(T k) { return pto(x/k, y/k); }
	// pto product
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
struct poly{
	vector<pto> pt;
	poly(){}
	poly(vector<pto> pt_) : pt(pt_) {}
	void delete_collinears() { // delete collinear points
		deque<pto> nxt; int len = 0;
		forn(i,sz(pt)) {
			if(len>1 && abs((pt[i]-nxt[len-2])^(nxt[len-1]-nxt[len-2])) <= EPS)
				nxt.pop_back(), len--; 
			nxt.pb(pt[i]); len++;
		}
		if(len>2 && abs((nxt[1]-nxt[len-1])^(nxt[0]-nxt[len-1])) <= EPS) 
			nxt.pop_front(), len--;
		if(len>2 && abs((nxt[len-1]-nxt[len-2])^(nxt[0]-nxt[len-2])) <= EPS)
			nxt.pop_back(), len--;
		pt.clear(); forn(i,sz(nxt)) pt.pb(nxt[i]);
	}
	void normalize() {
		delete_collinears();
		if(pt[2].left(pt[0], pt[1])) reverse(pt.begin(), pt.end()); //make it CW
		int n = sz(pt), pi = 0;
		forn(i, n)
			if(pt[i].x<pt[pi].x || (pt[i].x==pt[pi].x && pt[i].y<pt[pi].y))
				pi = i;
		rotate(pt.begin(), pt.begin()+pi, pt.end());
	}
	bool is_convex() { // delete collinear points first
		int N = sz(pt);
		if(N < 3) return false;
		bool isLeft = pt[0].left(pt[1], pt[2]);
		forr(i, 1, sz(pt))
			if(pt[i].left(pt[(i+1)%N], pt[(i+2)%N]) != isLeft)
				return false;
		return true; 
	}
	// for convex or concave polygons
	// excludes boundaries, check it manually
	bool inside(pto p) { // O(n)  
		bool c = false;
		forn(i, sz(pt)) {
			int j = (i+1)%sz(pt);
			if((pt[j].y>p.y) != (pt[i].y > p.y) && 
			(p.x < (pt[i].x-pt[j].x)*(p.y-pt[j].y)/(pt[i].y-pt[j].y)+pt[j].x))
				c = !c;
		}
		return c;
	}
	bool inside_convex(pto p) { // O(lg(n)) normalize first
		if(p.left(pt[0], pt[1]) || p.left(pt[sz(pt)-1], pt[0])) return false;
		int a = 1, b = sz(pt)-1;
		while(b-a > 1){
			int c = (a+b)/2;
			if(!p.left(pt[0], pt[c])) a = c;
			else b = c;
		}
		return !p.left(pt[a], pt[a+1]);
	}
	// cuts this along line ab and return the left side 
	// (swap a, b for the right one)
	
	// addition of convex polygons
	poly minkowski(poly p) { // O(n+m) n=|this|,m=|p| 
		this->normalize(); p.normalize();
		vector<pto> a = (*this).pt, b = p.pt;
		a.pb(a[0]); a.pb(a[1]);
		b.pb(b[0]); b.pb(b[1]);
		vector<pto> sum;
		int i = 0, j = 0;
		while(i < sz(a)-2 || j < sz(b)-2) {
			sum.pb(a[i]+b[j]);
			T cross = (a[i+1]-a[i])^(b[j+1]-b[j]);
			if(cross <= 0 && i < sz(a)-2) i++;
			if(cross >= 0 && j < sz(b)-2) j++;
		}
		return poly(sum);
	}
	pto farthest(pto v) { // O(log(n)) for convex polygons
		if(sz(pt)<10) {
			int k=0;
			forr(i,1,sz(pt)) if(v * (pt[i] - pt[k]) > EPS) k = i;
			return pt[k];
		}
		pt.pb(pt[0]);
		pto a=pt[1] - pt[0];
		int s = 0, e = sz(pt)-1, ua = v*a > EPS;
		if(!ua && v*(pt[sz(pt)-2]-pt[0]) <= EPS){ pt.pop_back(); return pt[0];}
		while(1) {
			int m = (s+e)/2; pto c = pt[m+1]-pt[m];
			int uc = v*c > EPS;
			if(!uc && v*(pt[m-1]-pt[m]) <= EPS){ pt.pop_back(); return pt[m];}
			if(ua && (!uc || v*(pt[s]-pt[m]) > EPS)) e = m;
			else if(ua || uc || v*(pt[s]-pt[m]) >= -EPS) s = m, a = c, ua = uc;
			else e = m;
			assert(e > s+1);
		}
	}
	
	// area ellipse = M_PI*a*b where a and b are the semi axis lengths
	// area triangle = sqrt(s*(s-a)(s-b)(s-c)) where s=(a+b+c)/2
	ld area(){ // O(n)
		ld area = 0;
		forn(i, sz(pt)) area += pt[i]^pt[(i+1)%sz(pt)];
		return abs(area)/ld(2);
	}

    
	// returns one pair of most distant points
	pair<pto,pto> callipers() { // O(n), for convex  poly, normalize first
		int n = sz(pt);
		if(n <= 2) return {pt[0], pt[1%n]};
		pair<pto,pto> ret = {pt[0], pt[1]};
		T maxi = 0; int j = 1;
		forn(i,sz(pt)) {
			while(((pt[(i+1)%n]-pt[i])^(pt[(j+1)%n]-pt[j]))<-EPS)j=(j+1)%sz(pt);
			if(pt[i].dist(pt[j]) > maxi+EPS)
				ret = {pt[i], pt[j]}, maxi = pt[i].dist(pt[j]);
		}
		return ret;
	}
	pto centroid(){ // (barycenter, mass center, needs float points)
		int n = sz(pt);
		pto r(0,0); ld t=0;
		forn(i,n) {
			r = r + (pt[i] + pt[(i+1)%n]) * (pt[i] ^ pt[(i+1)%n]);
			t += pt[i] ^ pt[(i+1)%n];
		}
		return r/t/3;
	}
};


pto C(0,0); // Store the center in C
bool radial(pto a, pto b){
    a = a-C; b = b-C;
    if(buenas(a) ^ buenas(b))return buenas(b);
    if((a^b) == 0)return a.norm_sq() < b.norm_sq(); //Adjust this case to define an order for those in the same angle or in the center
    //Note that for points at the same angle, this code puts closer to the center first
    //Note that if a point is at the center this code puts it very first
    return (a^b) > 0;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    ld a=0;
    while(n--){
        int k;
        cin >> k;
        vector<pto> v(k);
        //ld xt = 0, yt = 0;
        forn(i, k){
            int x, y;
            cin >> x >> y;
            v[i] = pto(x, y);
            //xt += v[i].x;
            //yt += v[i].y;
        }

        //C = pto(xt / k, yt / k);
        //dbg(C.x); dbg(C.y);

        //sort(all(v), radial);
        //forn(i, k) cout << v[i].x << ' ' << v[i].y << '\n';
        poly p(v);
        a += p.area(); 
    }
    cout << ll(a) << '\n';
    
    return 0;
}