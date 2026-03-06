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

typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;

vector<ld> fact(34);

ld comb(ll n, ll k) {
  if (k < 0 || n < k) return 0;
  return fact[n] / (fact[k] * fact[n - k]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    string s; cin >> s;
    int a = 0, b = 0, c = 0;
    for(char x : s) {
        if(x == 'r') a++;
        else if(x == 'g') b++;
        else c++;
    }
    if(b <= c and b <= a) swap(a, b);
    else if(c <= b and c <= a) swap(a, c);
    if(c <= b) swap(b, c);

    cout << fixed << setprecision(8);
    if(a == 0) {
        cout << 3.0 * b << '\n';
        return 0;
    }

    fact[0] = 1;
    forr(i, 1, 34) fact[i] = fact[i - 1] * i;

    ld ans = (3/2.0) * a;
    forn(i, a + 1) ans += (comb(a, i) * 3 * min(b + i, c + (a - i))) / (ld)(1ll << a);
    
    cout << ans << '\n';

    return 0;
}