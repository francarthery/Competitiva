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
        int n;
        cin >> n;
        vector<ii> v(n);
        vector<int> inter(2 * n + 1), unos(2 * n + 1);
        for(auto &[a, b] : v) cin >> a >> b;

        forn(i, n) if(v[i].fr == v[i].sc){ 
            inter[v[i].fr] = 1; 
            unos[v[i].fr]++;
        }
        forr(i, 1, 2 * n + 1) inter[i] += inter[i - 1];

        //vdbg(inter);
        forn(i, n){
            if(inter[v[i].sc] - inter[v[i].fr - 1] != v[i].sc - v[i].fr + 1 or (v[i].sc == v[i].fr and unos[v[i].fr] < 2)) cout << 1;
            else cout << 0;
        }
        cout << '\n';        

    }

    
    return 0;
}