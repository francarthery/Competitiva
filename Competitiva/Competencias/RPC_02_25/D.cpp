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
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<string> pal(n), num(m);
    forn(i, n) cin >> pal[i];
    forn(i, m) cin >> num[i];

    forn(i, m){
        vector<string> res;
        forn(j, n){
            if(sz(pal[j]) != sz(num[i])) continue;
            bool flag = true;
            forn(k, sz(pal[j])){
                if(num[i][k] == '2' and !(pal[j][k] >= 'a' and pal[j][k] <= 'c')) flag = false;
                if(num[i][k] == '3' and !(pal[j][k] >= 'd' and pal[j][k] <= 'f')) flag = false;
                if(num[i][k] == '4' and !(pal[j][k] >= 'g' and pal[j][k] <= 'i')) flag = false;
                if(num[i][k] == '5' and !(pal[j][k] >= 'j' and pal[j][k] <= 'l')) flag = false;
                if(num[i][k] == '6' and !(pal[j][k] >= 'm' and pal[j][k] <= 'o')) flag = false;
                if(num[i][k] == '7' and !(pal[j][k] >= 'p' and pal[j][k] <= 's')) flag = false;
                if(num[i][k] == '8' and !(pal[j][k] >= 't' and pal[j][k] <= 'v')) flag = false;
                if(num[i][k] == '9' and !(pal[j][k] >= 'w' and pal[j][k] <= 'z')) flag = false;
            }

            if(flag) res.pb(pal[j]);
        }
        sort(all(res));
        cout << sz(res);
        for(auto k : res) cout << ' ' << k;
        cout << '\n';
    }


    
    return 0;
}