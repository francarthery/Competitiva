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
        vector<bool> v(n), test(n), res1(n);
        string s; cin >> s;
        forn(i, n) v[i] = s[i] - '0';
        forn(i, n) if(i % 2 == 0) test[i] = 1;

        forn(i, n) res1[i] = test[i] ^ v[i];
  
        vector<int> aux(n);
        int ant = res1[0];
        forr(i, 1, n) {
            aux[i] = aux[i-1];
            if(res1[i] != ant) aux[i]++;
            ant = res1[i]; 
        }

        forn(i, q) {
            int l, r, k; cin >> l >> r >> k; l--; r--;
            if((aux[r] - aux[l] + 1) / 2 <= k) cout << "YES\n";
            else cout << "NO\n";
        }
    }



    return 0;
}