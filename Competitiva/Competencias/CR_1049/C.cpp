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
        ll n; cin >> n; 
        vector<ll> v(n);
        ll cost = 0;
        forn(i, n) {
            cin >> v[i];
            if(i % 2) cost -= v[i];
            else cost += v[i];
            v[i] = 2 * v[i];
        }

        ll ma = 0;
        if(n % 2 and n > 2) ma = n - 1;
        else if(n > 2) ma = n - 2;

        set<ll> neg, pos;
        if(n % 2) pos.insert(v.back() - n + 1);
        else neg.insert(v.back() + n - 1);

        dfor(i, n - 1){
            if(i % 2) { //estoy en neg
                ma = max(ma, v[i] - *pos.begin() - i); 
                neg.insert(v[i] + i);
            }
            else {
                ma = max(ma, *neg.rbegin() - v[i] - i);
                pos.insert(v[i] - i);
            }
        }
        cout << cost + ma << '\n';
    }

    return 0;
}