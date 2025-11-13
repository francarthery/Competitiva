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
        int n; cin >> n;
        vector<int> v(n);
        unordered_set<int> sumas{0}, aux{0}, aux1;
        forn(i, n) cin >> v[i];

        forn(i, n){
            aux1.clear();
            for(auto &j : aux) aux1.insert(j + v[i]);
            sumas.insert(all(aux1));
            aux = aux1;
            aux.insert(0);
        }
        vector<int> sums(all(sumas));
        sort(all(sums));
        cout << sz(sums) << '\n';
        forn(i, sz(sums)) cout << sums[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}