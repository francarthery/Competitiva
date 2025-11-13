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
vector<string> v;
vector<vector<ii>> clr;
int n, m; 

vector<vector<ll>> ps;

void cargarPrefixSum(){
    forr(i, 1, n + 1){
        forr(j, 1, m + 1){
            ps[i][j] = ('#' == v[i - 1][j - 1]) + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }
}

int query(int x1, int y1, int x2, int y2){
    int ans = ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
    return ans;
}

bool painted(int i, int j){


    forr(k,0,sz(clr[i])){
        if(k < 0) continue;
        if(j>=clr[i][k].first && j<= clr[i][k].second) return true;
    }

    return false;

}

bool paint(int fil, int col, int k) {
    if(fil+k > n or col+k > m) return false;

    if(painted(fil, col+k-1)) return false;
    if(painted(fil+k-1, col+k-1))return false;
    if(painted(fil+k-1, col))return false;

    forr(i,fil, fil+k) {
        clr[i].push_back({col, col+k-1});
    }
    return true;
}

int main(){

    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n >> m;
    clr = vector<vector<ii>>(n);
    ps = vector<vector<ll>>(n+5, vector<ll> (m+5));
    v.resize(n);
    forn(i, n) cin >> v[i];

    cargarPrefixSum();

    forr(u,0,n+1) {
        forr(i,0,m+1) {
            cout << ps[u][i] <<" ";
        }nl;
    }

    vector<vector<ii>> sig(n, vector<ii> (m));
    ii ant = {n,m};
    for(int i = n - 1; i >= 0; i--){
        sig[i][m - 1] = ant;
        for(int j = m - 2; j >= 0; j--){
            sig[i][j] = ant;
            if(v[i][j] == '#') ant = {i, j};
        }
    }

    int ans = 1;
    forr(___,1,min(n,m)){
        int k = ___+1;
        int can = 1;

        clr.clear();

        forr(i,0,n){

            for(int j=0; j<m && can; ){
                if(i>=n) break;
                if(v[i][j] != '#'){
                    auto x = sig[i][j];
                    i = x.first;
                    j = x.second;
                    if(j>=m) continue;
                    if(i>=n) break;
                }
                
                int pinte = 0;
                while(j<m && painted(i,j) == true){
                    j += k;
                    pinte = 1;
                    if(j>=m) break;
                }

                if(pinte) continue;


                ll cub = k*k;
                dbg(cub);
                dbg(query(i+1,j+1,i+k,j+k));
                if(!painted(i,j)){
                    if(j+k <= m && i+k <= n){
                        if(query(i+1,j+1,i+k,j+k) != cub){
                            can = 0;
                            break;
                        } else {
                            if(paint(i,j,k) == false) {
                                can = 0;
                                break;
                            }
                            j += k;
                            if(j>=m) continue;
                            if(v[i][j] == '#') {
                                j--;
                                continue;
                            }
                        }
                        if(can == 0) break;
                    } else {
                        can = 0;
                        break;
                    }
                }
            }
            if(can == 0) break;
        }
        if(can) ans = k;
    }

    cout << ans;nl;
    return 0;return 0;return 0;return 0;

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
    cout << res << '\n';

    return 0;
}