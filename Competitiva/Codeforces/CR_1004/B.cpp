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

    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        map<int, int> m;
        forn(i, n) {
            cin >> x;
            m[x]++;
        }

        vector<ii> v(all(m));
        bool flag = true;
        forn(i, sz(v)){
            if(i < sz(v) - 1 and v[i].fr + v[i].sc / 2 >= v[i + 1].fr){
                v[i + 1].sc += v[i].sc - (v[i + 1].fr - v[i].fr) * 2;
            }
            else if(v[i].sc % 2) flag = false;
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
    
    return 0;
}