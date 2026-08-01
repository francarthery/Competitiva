#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(x) (int(x.size()))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r", stdin);
    freopen("out","w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<vector<bool>> v(n, vector<bool>(m));
    forn(i, n) forn(j, m) {
        int x; cin >> x;
        v[i][j] = x;
    }

    if(n == 1) {
        cout << "YES\n";
        cout << 0 << '\n';
        forn(i, m) cout << v[0][i];
        cout << '\n';
        return 0;
    }

    forn(i, n) { //el que puede quedar de dos colores
        vector<bool> mask(m);
        vector<vector<bool>> aux = v;

        int base = 0;
        if(!i) base++; //la que uso de referencia

        forn(j, m) mask[j] = v[base][j];

        bool ok = true;
        forn(j, n) {
            forn(k, m) aux[j][k] = (aux[j][k] ^ mask[k]); //invierto el resto de acuerdo a eso

            int cambio = 0;
            forn(k,m-1) if(aux[j][k] != aux[j][k+1]) cambio++;

            if(j == i and cambio > 1) ok = false;
            else if(j != i and cambio) ok = false;
        }    
            
        if(ok) {
            cout << "YES\n";
            vector<bool> ansrow(n);
            forn(j, n) {
                if(j < i and aux[j][0] == 1) ansrow[j] = 1;
                else if(j == i) {
                    if(aux[j][0] == 1) ansrow[j] = 1;
                }
                else if(j > i and aux[j][0] == 0) ansrow[j] = 1;
            }
            forn(j, n) cout << ansrow[j];
            cout << '\n'; 
            forn(j, m) cout << mask[j];
            cout << '\n';
            return 0;
        }

        
    }

    cout << "NO\n";

    return 0;
}