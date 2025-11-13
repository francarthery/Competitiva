#include<bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define sz(a) ((int)(a.size()))
#define all(a) a.begin(), a.end()
#define dbg(x) cout << #x <<" "<< x << endl;
#define ws <<" "<<
#define nl cout << "\n";
#define vdbg(x) cout << "[ "; for(auto i : x) cout << i << ", ";cout << " ]"; nl;
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int mcd(int x, int y){ //O(log(n)) siendo n = (min(x, y))
	if(y == 0) return x;
	else return mcd(y, x % y);
}
vector<vector<int>> clr;
vector<string> v;
int n, m; 

bool paint(int fil, int col, int k) {
    // inicio, largo
    forr(i,fil, fil+k){
        forr(j,col,col+k){
            if(i>=n || j>=m) return false;
            if(v[i][j] != '#') return false;
            if(clr[i][j]==k){
                return false;
            }
            clr[i][j] = k;
        }
    }
    return true;

}
int main(){

    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n >> m;
    clr = vector<vector<int>>(n, vector<int> (m));
    v.resize(n);
    forn(i, n) cin >> v[i];


    int res = 0;
    forn(i, n){
        int cont = 0;
        forn(j, m) {
            if(v[i][j] == '#') cont++;
            else {
                res = mcd(res, cont);
                cont = 0;
            }
        }
        res = mcd(res, cont);
    }
    
    forn(j, m){
        int cont = 0;
        forn(i, n) {
            if(v[i][j] == '#') cont++;
            else {
                res = mcd(res, cont);
                cont = 0;
            }
        }
        res = mcd(res, cont);
    }

    int ans = 1;
    forr(___,1,res){
        int k = ___+1;
        if(res % k) continue;
        int can = 1;
        forr(i,0,n){
            for(int j=0; j<m && can; j++){
                int ppp = 0;
                while(j < m && clr[i][j] == k){
                    //viendo cuadros
                    ppp = 1;
                    j+=k;
                }
                if(j < m && clr[i][j] != k && v[i][j] == '#'){
                    //pintando pizza
                    if(paint(i,j,k) == 0) can = 0;
                    j+=k-1;
                } else {
                    j -= ppp;
                }
                
            }
           
        }
        if(can) ans = k;
    }

    cout << ans;nl;
    return 0;

    
    cout << res << '\n';

    return 0;
}