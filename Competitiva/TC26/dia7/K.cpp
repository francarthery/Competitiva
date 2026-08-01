#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) (int(x.size))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' '; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    int ind = 0, fin = n - 1;
    while(ind < n and v[ind] >= 0) ind++;
    while(fin >= 0 and v[fin] >= 0) fin--;
    
    if(ind == n){
        cout << 0 << '\n';
        return 0;
    }

    bool ant = 1;
    int opcion = fin != n - 1 ? n - fin - 1 : 1e6, cont = 0;
    int cambios = (ind <= fin ? 1 : 0);
    if(fin != n - 1) cambios++;
    vector<int> ops;

    
    forr(i, ind, fin + 1){
        if(v[i] < 0){
            k--;
            if(cont) ops.push_back(cont), cont = 0;
        }
        if(v[i] < 0 and !ant){
            ant = !ant;
            cambios++;
        }
        if(v[i] >= 0) cont++;
        if(v[i] >= 0 and ant){
            cambios++;
            ant = !ant;
        }
    }
    
    if(cont) ops.push_back(cont);
   
    if(k < 0){
        cout << "-1\n"; 
        return 0;
    }
    sort(all(ops)); 
    forn(i, ops.size()){
        if(ops[i] > k) break;
        k-= ops[i];
        cambios-= 2;
    }
    
    if(k >= opcion) cambios--;

    cout << cambios << '\n';
    
    return 0;
}