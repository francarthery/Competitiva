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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    typedef long double T;
    #define sqr(x) ((x)*(x))

    function<T(ii, ii, ii&)> precta = [&](ii a, ii b, ii& punto) -> T{ //Recta que pasa por los puntos a y b 
        ll area = (a.fr - b.fr) * (a.sc - punto.sc) - (a.sc - b.sc) * (a.fr - punto.fr);
        T base = sqrtl(sqr(a.fr - b.fr) + sqr(a.sc - b.sc));
        return (abs((T)area) / base); 
    };



    return 0;
}