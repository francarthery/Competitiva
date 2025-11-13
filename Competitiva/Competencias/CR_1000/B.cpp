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

    int t;
    cin >> t;
    while(t--){
        int l, r, n;
        cin >> n >> l >> r;
        vector<int> v(n), vc, vl, vr;
        forn(i, n) cin >> v[i];
        
        forn(i, l - 1) vl.pb(v[i]);
        forr(i, l - 1, r) vc.pb(v[i]);
        forr(i, r, n) vr.pb(v[i]);

        sort(all(vr));
        sort(all(vl));
        sort(rall(vc));

        ll v1 = 0, v2 = 0;

        forn(i, sz(vc)){
            if(i >= sz(vr)) v1 += vc[i];
            else v1 += min(vc[i], vr[i]);
        }

        forn(i, sz(vc)){
            if(i >= sz(vl)) v2 += vc[i];
            else v2 += min(vc[i], vl[i]);
        }

        cout << min(v1, v2) << '\n';
    }


    
    return 0;
}