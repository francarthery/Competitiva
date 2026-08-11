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

ll expMod(ll b, ll e, ll m) {  // O(log e)
    if (e < 0) return 0;
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
        b = b * b % m;                 // b = mulMod(b,b,m);
        e >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int e = -1, o = -1;
        forn(i, n) {
            if(s[i] == '?') continue;
            if(i % 2 == 0 and e == -1) e = i;
            else if(i % 2 and o == -1) o = i;
        }

        bool ok = true;
        forn(i, n) {
            if(s[i] == '?') continue;

            if(i%2==0 and e != -1) {
                int dist = abs(e - i) / 2;
                if(dist % 2 == 0 and s[i] != s[e] or dist % 2 and s[i] == s[e]) ok = false;
            }
            else if(i%2 and o != -1) {
                int dist = abs(o - i) / 2;
                if(dist % 2 == 0 and s[i] != s[o] or dist % 2 and s[i] == s[o]) ok = false;
            }
        }
        // dbg(e); dbg(o);

        if(!ok) cout << 0;
        else if(e != -1 and o != -1) cout << 1;
        else if(e != -1 or o != -1) cout << 2;
        else cout << 4;
        cout << '\n';
    }



    return 0;
}