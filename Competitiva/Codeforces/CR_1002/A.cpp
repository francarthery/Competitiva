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

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n), b(n);
        forn(i, n) cin >> a[i]; 
        forn(i, n) cin >> b[i];

        map<int, int> ma, mb;
        forn(i, n) ma[a[i]]++;
        forn(i, n) mb[b[i]]++;

        if(sz(ma) >= 3 or sz(mb) >= 3 or (sz(ma) >= 2 and sz(mb) >= 2)) cout << "YES\n";
        else cout << "NO\n";

    }


    
    return 0;
}