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

    int t; cin >> t;
    while(t--) {
        int n, x, y; cin >> n;
        n = 2*n+1;

        auto out = [&](vector<int> &v) {
            cout << "? " << sz(v) << ' ';
            for(int i : v) cout << i << ' ';
            cout << endl;
        };

        int der, izq;
        int l = 2, r = n + 1;
        while(r-l>1) {
            int m = (r+l)/2;
            vector<int> ans;
            forn(i, m) ans.pb(i+1);
            out(ans);
            cin >> x;
            if(x % 2 != sz(ans) % 2) r = m;
            else l = m;
        }

        der = r;
        l = 0, r = n - 1;
        while(r-l>1){
            int m = (r+l)/2;
            vector<int> ans;
            forr(i, m, n+1) ans.pb(i);
            out(ans);
            cin >> x;
            if(x % 2 != sz(ans) % 2) l = m;
            else r = m;
        }

        izq = l;

        vector<int> ans;
        forr(i, izq, der) ans.pb(i);
        l = izq, r = der;
        while(r-l>1){
            int m = (r+l)/2;
            vector<int> ans;
            forr(i, izq, m+1) ans.pb(i);
            ans.pb(der);
            out(ans);
            cin >> x;
            if(x%2 != sz(ans)%2) r = m;
            else l = m;
        }

        cout << "! " << izq << ' ' << der << ' ' << r << endl;
    }



    return 0;
}