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
#define sqr(a) ((a) * (a))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

struct punto{
    ld x, y;
    punto(ld X, ld Y) : x(X), y(Y) {};
};

vector<punto> f(punto c1, ld r1, punto c2, ld r2){ //Mando los dos centros y los dos radios de los circulos
    vector<punto> inter; //Retorno un vector de puntos con las dos intersecciones
    r1 = sqr(r1); r2 = sqr(r2);
    ld d = sqrtl(sqr(c1.x - c2.x) + sqr(c1.y - c2.y));
    ld l = (r1 - r2 + sqr(d)) / (2 * d);
    ld h = sqrtl(r1 - sqr(l));
    ld x1 = (l / d) * (c2.x - c1.x) + (h / d) * (c2.y - c1.y) + c1.x;
    ld y1 = (l / d) * (c2.y - c1.y) - (h / d) * (c2.x - c1.x) + c1.y;
    ld x2 = (l / d) * (c2.x - c1.x) - (h / d) * (c2.y - c1.y) + c1.x;
    ld y2 = (l / d) * (c2.y - c1.y) + (h / d) * (c2.x - c1.x) + c1.y;
    inter.pb(punto(x1, y1)); inter.pb(punto(x2, y2)); 
    return inter;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifdef fran
		//freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif

	vector<punto> inter = f(punto(1,2), 3, punto(3,4), 5);
    cout << inter[0].x << ' ' << inter[0].y << '\n';
    cout << inter[1].x << ' ' << inter[1].y << '\n';

	return 0;
}