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

    int t; cin >> t;
    while(t--){
        int n, x, y; cin >> n >> x >> y;
        vector<int> v(n);
        forn(i, n) cin >> v[i];

        deque<int> a, b, c;
        forn(i, x) a.pb(v[i]);
        forr(i, x, y) b.pb(v[i]);
        forr(i, y, n) c.pb(v[i]);

        int mi = *min_element(all(b));
        while(b.front() != mi){
            b.pb(b.front());
            b.pop_front();
        }

        int ind = -1;
        forn(i, sz(a)) {
            if(a[i] > b.front()) {
                ind = i;
                break;
            }
        }

        if(ind != -1) while(sz(a) > ind){
            c.push_front(a.back());
            a.pop_back();
        }

        while(sz(c) and c.front() < b.front()){
            a.pb(c.front());
            c.pop_front();
        }

        for(int i : a) cout << i << ' ';
        for(int i : b) cout << i << ' ';
        for(int i : c) cout << i << ' ';
        cout << '\n';
    }



    return 0;
}