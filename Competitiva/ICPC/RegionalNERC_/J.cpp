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
        string s; cin >> s;
        vector<string> shifteo(sz(s));

        int n = sz(s);

        forn(i,n){
            forn(l,n){
                shifteo[i]+=s[(i+l)%n];
            }
        }
        reverse(shifteo.begin() + 1, shifteo.end());
        // forr(i, 1, sz(s)){
        //     forr(j, i, sz(s)){
        //         shifteo[i] += s[j];
        //     }
        //     forn(j, i) shifteo[i] += s[j];
        // }
        
        set<ll> ans;
        forr(i, 1, sz(s)){
            if(shifteo[i] < s) continue;
            ll x = stoll(shifteo[i]) - stoll(s);
            if(shifteo[x % sz(s)] == shifteo[i]) ans.insert(x);
        }

        cout << sz(ans) << '\n';
        for(auto e : ans) cout << e << ' ';
        cout << '\n';
    }

    return 0;
}