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
typedef long double ld;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ld s1, x1, y1, s2, x2, y2;
    cin >> s1 >> x1 >> y1 >> s2 >> x2 >> y2;

    bool flag; int cont = 0;
    ld d = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    ld l = 0, r = 100000, fa, fb, a, b; //Ternary search sobre la fuerza
    do{ 
        a = (l * 2 + r) / 3.0, b = (l + r * 2) / 3.0;
        ld r1a = sqrtl(s1 / a), r2a = sqrtl(s2 / a);
        ld r1b = sqrtl(s1 / b), r2b = sqrtl(s2 / b);
        ld ya = (r1a * r1a - r2a * r2a + d * d) / (2 * d);
        ld yb = (r1b * r1b - r2b * r2b + d * d) / (2 * d);
        fa = sqrtl(r1a * r1a - ya * ya) * 2;
        fb = sqrtl(r1b * r1b - yb * yb) * 2;

        flag = r1a + d < r2a or r1b + r2b < d;
        if(!(r1a + d < r2a) and (r1b + r2b < d or fa > fb)) r = b;
        else l = a;
        cont++;
    }
    while((flag or abs(fa - fb) > 1e-12) and cont < 200);

    cout << fixed << setprecision(8) << acosl(-1) * ((fa * fa) / 4.0) << '\n';
    
    return 0;
}