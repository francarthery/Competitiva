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

    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> r(n), p(m), p2, p3;
        forn(i, n) cin >> r[i];
        forn(i, m) cin >> p[i];

        int kev = r.front();
        sort(all(r));
        sort(all(p));
        forn(i, m){
            if(p[i] <= kev or p[i] > r.back()) p2.pb(p[i]);
            else p3.pb(p[i]);
        }

        forr(i, 1, m + 1){
            ll inicio = m % i, cont = m / i;
            if(m - m % i <= sz(p2)){
                cout << cont << ' ';
                continue;
            }

            for(int j = inicio; j < ((sz(p3) - inicio) / i) * i; j += i){
                cont += n - (lower_bound(all(r), p3[j]) - r.begin());
            }
            if((sz(p3) - inicio) % i){
                cont += n - (lower_bound(all(r), p3[sz(p3) - (sz(p3) - inicio) % i]) - r.begin());
            }
            
            cout << cont << ' ';
        }   
        cout << '\n';
    }
    
    return 0;
}