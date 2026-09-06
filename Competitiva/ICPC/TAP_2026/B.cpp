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

void solve() {
    string s; cin >> s;
    vector<string> pos, pals{"AGASA","EGASE","IGASI","OGASO","UGASU"};
    forn(i, sz(s)-4) {
        forn(j, 5) if(s.substr(i, 5) == pals[j]) {
            pos.push_back(s.substr(0, i+1) + s.substr(i+5));
            i+=4;
            break;
        }
    }
    
    bool ok = true;
    forn(i, sz(pos)) {
        forr(j, i+1, sz(pos)) {
            if(pos[i] != pos[j]) ok = false; 
        }
    }

    if(!sz(pos)) cout << "-\n";
    else if(!ok) cout << "+\n";
    else cout << pos[0] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t = 1;
    while(t--) solve();

    return 0;
}