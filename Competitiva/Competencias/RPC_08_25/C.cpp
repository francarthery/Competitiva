#include <bits/stdc++.h>

#define rec(i, a, b) for(int i=a; i<b; ++i)
#define rev(i, a, b) for(int i=b; i>=a; --i)

#define all(d) d.begin(), d.end()
#define rall(d) d.rbegin(), d.rend() 
#define tm(x) (int)x.size()

#define nl cout<<"\n";
#define ws <<" "<<
#define bf cout << endl;
#define raya cout << "=====================";bf;

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
typedef long double ld;
const ld PPPPP = acosl(-1);
typedef long double T; // double could be faster but less precise
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

const int N = 101;
int C, n;
vector<pto> pc(N);
struct tdp{
	long double x = -2;
};
vector<unordered_map<bitset<N>, tdp>> dp(N);

ld calc(bitset<N> &u){
	pto last, first;
	ld ret = 0;
	int i=0;
	while(!u[i]) i++;
	first = last = pc[i];
	rec(j,i+1,C){
		if(u[j]){
			ret += abs(last ^ pc[j]);
			last = pc[j];
		}
	}
	ret += abs(last ^ first);
	//cout << abs(ret) / (ld)2.0;nl;
	return abs(ret) / (ld)2.0;
}
	

ld f(int i, bitset<N> &u, int count){
	if(count == n) {
		return dp[i][u].x = calc(u);
	}
	if(i >= C) return 0;
	ld &ret = dp[i][u].x;
	if(ret != -2) return ret;
	ret = f(i+1, u, count);
	u.set(i);
	ret = max(ret, f(i+1, u, count + 1));
	u.reset(i);
	return ret;
}

void solve(){
	
	cin >> C >> n;
	
	rec(i,0,C) {
		ld x;
		cin >> x;
		ld ang = x*2*PPPPP/(ld)360.0;
		pc[i] = pto(cosl(ang)*1000.0, sinl(ang)*1000.0);
	}
	bitset<N> xd(C);
	rec(i,0,N) xd.reset(i);
	cout << fixed << setprecision(15) << f(0,xd,0);nl;
}

int main(){	
	solve();
	return 0;
}