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

    int n; cin >> n;
    vector<ii> v(n);
    forn(i, n) {
        string a; cin >> a;
        int pos = 0;
        forn(i, sz(a)) if(a[i] == '-') pos = i; 
        v[i] = {stoi(a.substr(0, pos)), stoi(a.substr(pos+1))};
        if((v[i].fr + v[i].sc) % 4 == 3 or (v[i].fr + v[i].sc) % 4 == 0) swap(v[i].fr, v[i].sc);
    }
    //forn(i, n) cout << v[i].fr << ' ' << v[i].sc << '\n';

    bool ok = true;
    int err = 0;
    forn(i, n) {
        if(v[i].fr == 11 and v[i].sc == 11) {
            ok = false;
            err = i+1;
            break;
        }
        if(i == n-1) continue;
        if(v[i].fr > v[i+1].fr) {
            ok = false;
            err = i+2;
            break;
        }
        if(v[i].sc > v[i+1].sc) {
            ok = false;
            err = i+2;
            break;
        }
        if((v[i].fr == 11 or v[i].sc == 11) and (v[i+1].fr > v[i].fr or v[i+1].sc > v[i].sc)) {
            ok = false;
            err = i+2;
            break;
        }
    }

    if(ok) cout << "ok" << '\n';
    else cout << "error " << err << '\n';

    return 0;
}