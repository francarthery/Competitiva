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
#define sqr(x) ((x) * (x))
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef long double T; // double could be faster but less precise

struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    T x, y;
    int n;
    cin >> n;
    vector<pto> v(n);

    forn(i, n){
        cin >> x >> y;
        v[i] = pto(x, y);
    }
    
    T area = 0, fact = 0;

    forr(i, 1, n){
        fact += sqr(v[i].x - v[i - 1].x) + sqr(v[i].y - v[i - 1].y);

        if(v[i - 1].y >= 0 and v[i].y >= 0){
            area += (min(v[i].y, v[i - 1].y) + abs(v[i].y - v[i - 1].y) / 2.0) * (v[i].x - v[i - 1].x);
        }
        else if(v[i - 1].y <= 0 and v[i].y <= 0){
            area -= (-max(v[i].y, v[i - 1].y) + abs(v[i].y - v[i - 1].y) / 2.0) * (v[i].x - v[i - 1].x);
        }
        else{
            T pend = (v[i].y - v[i - 1].y) / (v[i].x - v[i - 1].x);
            if(v[i - 1].y >= 0) area -= v[i - 1].y / (pend);
            else area += v[i - 1].y / (pend);
        }
    }

    T aini = sqrtl(3) / 4.0, subarea = area, ant = -1;

    while(ant != area){
        ant = area;
        subarea *= fact;
        area += subarea;
    }

    cout << fixed << setprecision(9) << aini + 3 * area << '\n';
    
    return 0;
}