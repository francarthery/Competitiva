#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "<<;for(auto e : x) cout<<e<<" ";cout<<endl;}

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<string> v(n);
    forn(i, n) cin >> v[i];

    if(m > n) {
        vector<string> aux(m);
        forn(i, n) forn(j, m) aux[j] += v[i][j];
        swap(n, m);
        v = aux;
    }

    // forn(i, n) cout << v[i] << '\n';
    vector<vector<int>> w(n,vector<int>(m+1)), a(n,vector<int>(m+1)), 
    l(n, vector<int>(m+1)), d(n,vector<int>(m+1)), o(n,vector<int>(m+1));
    forn(i, n) {
        forn(j, m) {
            w[i][j+1] = w[i][j];
            a[i][j+1] = a[i][j];
            l[i][j+1] = l[i][j];
            d[i][j+1] = d[i][j];
            o[i][j+1] = o[i][j];

            if(v[i][j] == 'W') w[i][j+1]++; 
            if(v[i][j] == 'A') a[i][j+1]++; 
            if(v[i][j] == 'L') l[i][j+1]++; 
            if(v[i][j] == 'D') d[i][j+1]++; 
            if(v[i][j] == 'O') o[i][j+1]++; 
        }
    }

    ll best = 1e9;
    forn(i, m) forr(j, i, m) {
        vector<ll> last(5, -1e9);
        forn(k, n) {
            if(w[k][j+1] - w[k][i]) last[0] = k;
            if(a[k][j+1] - a[k][i]) last[1] = k;
            if(l[k][j+1] - l[k][i]) last[2] = k;
            if(d[k][j+1] - d[k][i]) last[3] = k;
            if(o[k][j+1] - o[k][i]) last[4] = k;

            ll worse = *min_element(all(last));
            if(worse == 1e9) continue;
            
            best = min(best, (ll)(j-i+1) * (ll)(k-worse+1));
        }
    }

    if(best == 1e9) cout << "impossible\n";
    else cout << best << '\n';

    return 0;
}