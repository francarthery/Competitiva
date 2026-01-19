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
        int n; string s;
        cin >> n >> s;

        int ini = 0, fin = n - 1;
        while(s[ini] == '0') ini++;
        while(s[fin] == '1') fin--;
        set<int> idx;

        int l = ini, r = fin;
        while(l < r) {
            if(s[r] == '1') r--;
            else if(s[l] == '0') l++;
            else {
                idx.insert(l);
                idx.insert(r);
                r--; l++;
            }
        }

        if(sz(idx)) {
            cout << "Alice\n";
            cout << sz(idx) << '\n';
            for(int i : idx) cout << i + 1 << ' ';
            cout << '\n';
        } else cout << "Bob\n";
    }



    return 0;
}