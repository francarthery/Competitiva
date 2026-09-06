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

    string s; cin >> s;
    
    ll acarreo = 0;
    s = "0"+s;
    dfor(i, sz(s)) {
        int res = (s[i] - '0') * 9 + acarreo;
        s[i] = res % 10 + '0';
        acarreo = res / 10; 
    }
    int ini = 0; 

    auto sum = [&](string &s) {
        dfor(i, sz(s)) {
            int dig = s[i] - '0';
            dig++;
            s[i] = dig % 10 + '0';
            if(dig != 10) break;
        }
    };

    ll ans = 0;
    while(ini < sz(s) - 1) {
        while(s[ini] > '0') {
            sum(s);
            s[ini]--;
            ans++;
        }
        ini++;
    }
    if(s[ini] != '0') ans++;

    cout << ans << '\n';

    return 0;
}