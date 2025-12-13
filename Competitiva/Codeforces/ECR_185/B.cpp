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
        int n; cin >> n;
        vector<ll> v(n), ps(n + 1);
        forn(i, n) cin >> v[i];
        sort(rall(v));
        forn(i, n) ps[i + 1] = ps[i] + v[i];

        while(!v.back()) v.pop_back();
        ll ma = 1, op = n;
        dfor(i, sz(v)){
            if(ps[i + 1] - (i + 1) >= op - 1){
                ma = i + 1;
                break;
            }
            else op -= v[i];
        }

        cout << ma << '\n';
    }


    return 0;
}