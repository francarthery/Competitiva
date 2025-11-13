#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(ld i = 0; i < n; i++)
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
const ld pi = 3.14159265358979323;

ld l, r;
ld f(ld h){
    ld R = r + sqrtl(l * l - h * h);
    return (pi / 2 * h * (r * r + R * R));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        cin >> l >> r;
        ld a, b, l1 = 0, r1 = l;
        forn(k, 60){
            a = ((ld)2 * l1 + r1) / (ld)3;
            b = ((ld)2 * r1 + l1) / (ld)3;
            if(f(a) > f(b)) r1 = b;
            else l1 = a;
        }
        cout << fixed << setprecision(8) << acosl(l1 / l) + pi / 2 << '\n';
    }    

    return 0;
}