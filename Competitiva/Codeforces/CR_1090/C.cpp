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
    while(t--) {
        int n; cin >> n;
        vector<int> v2(n), v3(n);
        forn(i,n) v2[n-1-i] = n+1+i;
        forn(i,n) v3[n-1-i] = 2*n+1+i;

        forn(i, n) {
            int sec, ter;
            if(sz(v2)) {
                sec = v2.back();
                v2.pop_back();
            }
            else {
                sec = v3.back();
                v3.pop_back();
            }
            if(sz(v2)) {
                ter = v2.back();
                v2.pop_back();
            }
            else {
                ter = v3.back();
                v3.pop_back();
            }
            cout << i+1 << ' ' << sec << ' ' << ter << ' ';
        }
        cout << '\n';
    }

    return 0;
}