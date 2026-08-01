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
        int n, q; cin >> n >> q;
        string s, t; cin >> s >> t;
        vector<int> p01(n+1), p10(n+1), p00(n+1), p11(n+1);
        forn(i, n) {
            p00[i+1] += p00[i];
            p11[i+1] += p11[i];
            p01[i+1] += p01[i];
            p10[i+1] += p10[i];
            if(s[i] == '0' and t[i] == '0') p00[i+1]++;
            else if(s[i] == '1' and t[i] == '1') p11[i+1]++;
            else if(s[i] == '0' and t[i] == '1') p01[i+1]++;
            else p10[i+1]++; 
        }

        forn(tt, q) {
            int l, r; cin >> l >> r;
            int c00 = p00[r] - p00[l-1];
            int c11 = p11[r] - p11[l-1];
            int c01 = p01[r] - p01[l-1];
            int c10 = p10[r] - p10[l-1];

            int neto = abs(c01 - c10);
            if(c00 + c11 >= neto) cout << "YES\n";
            else cout << "NO\n";
        }
    }



    return 0;
}