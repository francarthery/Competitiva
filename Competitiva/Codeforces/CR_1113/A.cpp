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
        string s; cin >> s;
        int prim=-1, prim0=-1;
        forn(i, sz(s)) {
            if(s[i] == '0' and prim0 == -1) prim0 = i;
            if(s[i] == '1' and prim == -1) prim = i;
        }
        if(prim < prim0) swap(prim, prim0);
        cout << s.substr(0, prim0) + s.substr(prim0+1, prim-prim0-1) + s.substr(prim+1) << '\n';

    }


    return 0;
}