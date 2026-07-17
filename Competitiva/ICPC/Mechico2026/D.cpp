#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int(x.size()))
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {for(auto e : x) cout<<e<<' '; cout<<endl;}

using namespace std;
typedef long long ll;
typedef pair<int,int>ii;
typedef long double ld;
typedef long long T;
#define sqr(x) ((x)*(x))
const T EPS = 1e-9;
const T inf = 1e18;

struct pto{
    T x,y;
    pto() : x(0), y(0) {}
    pto(T a, T b) : x(a), y(b) {}
    T norm_sq() {return x*x+y*y;}
    T nrom() {return sqrtl(x*x+y*y);}
    pto operator+ (pto a) {return pto(x+a.x, y+a.y);}
    pto operator- (pto a) {return pto(x-a.x, y-a.y);}
    pto operator* (T a) {return pto(x*a, y*a);}
    T dist_sq(pto b) {return ((b-(*this)).norm_sq());}
    T dist(pto b) {return sqrtl(dist_sq(b));}
};

int sgn(T x) {return x<0 ? -1 : !!x; }
struct line{
    T a,b,c;
    line(){};
    line(T x, T y, T z):a(x), b(y), c(z) {}
    
};

struct circle{
    T r;
    pto o;
    circle(){}
    circle(pto _x, T _r) {
        r=_r;
        o=_x;
    }
    bool inside(circle c){
        T d = (o - c.o).norm_sq();
        return d <= (c.r-r)*(c.r-r) + EPS;
    }
    bool inter(line l){
        ld a = l.a, b=l.b, c=l.c - l.a*o.x - l.b*o.y;
        if(c*c > r*r*(a*a+b*b) + EPS){
            return 0;
        } else {
            return 1;
        }
    }
    bool inter(circle c){
        line l;
        l.a = o.x - c.o.x;
        l.b = o.y - c.o.y;
        l.c = (sqr(c.r)-sqr(r) + sqr(o.x)-sqr(c.o.x)+sqr(o.y)-sqr(c.o.y))/2.0;
        return (*this).inter(l);
    }
};

void solve(){
    circle a,b;
    cin>>a.o.x>>a.o.y>>a.r;
    cin>>b.o.x>>b.o.y>>b.r;
    ll k;
    cin>>k;
    int f=0;
    if(a.inside(b) || b.inside(a)){
        if(max(b.r, a.r)*2ll >= k){
            f=1;
        }
    } else {
        if(a.inter(b) && a.o.dist(b.o) + a.r + b.r >= k){
            f=1;
        } else if( max(a.r, b.r)*2ll >= k){
            f=1;
        }
    }
    cout<<(f?"YES":"NO")<<endl;
}

int main(){
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;cin>>t;
    while(t--){
        solve();
    }


    
    return 0;
}
