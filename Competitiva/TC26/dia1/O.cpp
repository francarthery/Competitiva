#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define dbg(x) cout<<#x <<" = " << x << endl;
#define vdbg(x) {cout<<#x<<" = ["; for(auto e : x) cout<<e<<' '; cout<<"\n";}
#define nl cout<<"\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

typedef long double T; // double could be faster but less precise
typedef long double ld;
const T PI = acosl(-1);
const T EPS = 1e-9; // if T is integer, set to 0
const T INF = 1e18;
struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
	pto operator+(pto b) { return pto(x+b.x, y+b.y); }
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
	// dot product
	T operator*(pto b) { return x*b.x + y*b.y; }
    bool operator<(const pto &b) const {
		return x < b.x-EPS || (abs(x - b.x) <= EPS && y < b.y-EPS);
	}
	ld norm() { return sqrtl(x*x + y*y); }
};

ld angle(pto a, pto b) { // smallest angle bewteen a and b
	ld cost = (a*b) / a.norm() / b.norm();
	return acosl(max(ld(-1.), min(ld(1.), cost)));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<pair<pto, int>> v(n);
    forn(i, n) {
        cin >> v[i].first.x >> v[i].first.y;
        v[i].second = i;
    }
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(v.begin(), v.end(), rng);  // vector random shuffle

    vector<int> ans(n);
    ans[v[0].second] = 1;
    pto vec = v[0].first;
    forr(i, 1, n) {
        if((vec + v[i].first).norm() < (vec - v[i].first).norm()) {
            vec = vec + v[i].first;
            ans[v[i].second] = 1;
        }
        else {
            vec = vec - v[i].first;
            ans[v[i].second] = -1;
        }
    }

    for(int i : ans) cout << i << ' ';
    cout << '\n';

    
    return 0;
}