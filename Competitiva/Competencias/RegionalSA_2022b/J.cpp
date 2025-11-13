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
typedef tuple<ll, ll, ll> iii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int w, h, n; cin >> w >> h >> n;
    vector<iii> p;
    int x1, y1, x2, y2;
    forn(i, n){
        cin >> x1 >> y1 >> x2 >> y2;
        if((!x1 or !y1 or x1 == w or y1 == h) and (!x2 or !y2 or x2 == w or y2 == h)){
            p.pb({x1, y1, i});
            p.pb({x2, y2, i});
        }
    }

    auto f = [&](iii &a){
        auto &[x, y, _] = a;
        if(!y) return x;
        else if(x == w) return w + y;
        else if(y == h) return 2*w + h - x;
        else return 2*h + 2*w - y;
    };

    sort(all(p), [&](iii &a, iii &b){ return f(a) < f(b); });

    vector<int> st;
    vector<bool> vis(n);
    for(auto &[x, y, i] : p){
        if(vis[i]) {
            if(st.back() != i) {
                cout << "N\n";
                return 0;
            }
            else st.pop_back();
        }
        else {
            st.pb(i);
            vis[i] = true;
        }
    }

    cout << "Y\n";

    return 0;
}