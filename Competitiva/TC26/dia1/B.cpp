#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend9)()
#define dbg(x) cout<<#x <<" = " << x << endl;
#define vdbg(x) {cout<<#x<<" = ["; for(auto e : x) cout<<e<<' '; cout<<"\n";}
#define nl cout<<"\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<bool> dig(10);
    vector<vector<bool>> v(n, vector<bool>(10));

    forn(i, n) {
        forn(j, 6){
            int x; cin >> x; 
            v[i][x] = true;
            dig[x] = true;
        }
    }

    int falla = -1;
    forr(i, 1, 10) if(falla == -1 and !dig[i]) falla = i;

    vector<int> ind;
    forn(i, n) ind.push_back(i);

    // forn(i, n) vdbg(v[i]);
    // vdbg(ind);

    forr(i, 1, 10) {
        forn(j, 10) {
            bool ok = false;
            do {
                forn(k, n-1) {
                    if((v[ind[k]][i] and v[ind[k+1]][j])) ok = true;
                    
                }
                
                if(falla != -1) break;
            } while(next_permutation(all(ind)));

            if(!ok and falla == -1) {
                falla = i * 10 + j;
                break;
            }
            if(falla != -1) break;
        }
        if(falla != -1) break;
    }

    cout << falla-1  << '\n';
    
    return 0;
}