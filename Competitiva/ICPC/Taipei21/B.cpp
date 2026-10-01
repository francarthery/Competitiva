#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int) (x).size())
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto e : x) cout<<e<<" ";cout<<endl;}
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;

        vector<int> m(n+1);
        forn(i, n) m[i+1] = m[i] + (a[i] == b[i]);

        vector<vector<int>> m2(n, vector<int>(n+1)), m3(n, vector<int>(n+1));
        reverse(all(b));
        forn(k, n) forn(i, n-k) m2[k][i+1] = m2[k][i] + (a[i] == b[i+k]); //Shifteo a izquierda. Cuidado con runtime.
        forn(k, n) forr(i, k, n) m3[k][i+1] = m3[k][i] + (a[i] == b[i-k]); //Shifteo a derecha

        // vdbg(m);
        // forn(i, n) vdbg(m2[i]);
        // forn(i, n) vdbg(m3[i]);

        int best = -1, l, r;
        forr(tam, 1, n+1) forn(ini, n-tam+1) {
            int fin = ini + tam - 1;
            int now = m[ini] + (m[n] - m[fin+1]);
            
            int dfin = n - fin - 1;
            int desp = ini - dfin;

            if(desp > 0) now += m3[desp][fin+1] - m3[desp][ini];
            else now += m2[-desp][fin+1] - m2[-desp][ini];

            if(now > best) {
                best = now;
                l = ini;
                r = fin;
            }
        }

        cout << m[n] << ' ' << best << ' ' << l+1 << ' ' << r+1 << '\n';
    }

}