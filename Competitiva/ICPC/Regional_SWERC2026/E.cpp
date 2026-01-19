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

    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> p4(n + 1), p8(n + 1);
    forn(i, n) {
        p4[i + 1] = p4[i];
        p8[i + 1] = p8[i];
        if(s[i] == '4') p4[i + 1]++;
        else p8[i + 1]++;
    }

    int x, y, l, r;
    forn(i, q){
        cin >> l >> r >> x >> y;
        if(x < 0) x = -x;
        if(y < 0) y = -y;
        int c4 = p4[r] - p4[l - 1];
        int c8 = p8[r] - p8[l - 1];
        int px = 0, py = 0;

        //dbg(c4); dbg(c8); cout << '\n';
        px += min(c8, x);
        py += min(c8, y);
        if(x - px + y - py <= c4) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}