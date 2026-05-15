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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
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

    int n, m; cin >> n;
    m = 2*n-1;
    vector<string> v(n);
    forn(i, n) cin >> v[i];
    
    vector<int> r(n), c(m);
    int tot = 0;
    forn(i, n) forn(j, m) {
        r[i] += v[i][j] == 'C';
        c[j] += v[i][j] == 'C';
        tot += v[i][j] == 'C';
    }

    if(tot % 2) {
        cout << "impossible\n";
        return 0;
    }

    int need = tot / 2, mid = n - 1;
    auto vert = [&]() { //caso sweep de costado
        int col = 0, sum = 0;
        forn(i, m) {
            sum += c[i];
            if(sum >= need) {
                col = i;
                break;
            }
        }
        int uso = need - (sum - c[col]);
        
        if(col != mid) {
            forn(i, n) forn(j, col) if(v[i][j] != '#') v[i][j] = 'A';
            int pos = (col > mid ? 0 : n-1);
            int sum = (col > mid ? 1 : -1);
            while(uso) { //arriba para abajo
                if(v[pos][col] == 'C') uso--;
                if(v[pos][col] != '#') v[pos][col] = 'A';
                pos+=sum;
            }
            return true;
        }
        else {
            bool esp = true;
            forn(i, n) { //Solo estan los dos de arriba en el medio
                if(v[i][col] == 'C' and i >= 2) esp = false;
                else if(v[i][col] != 'C' and i < 2) esp = false;
            } 
            if(uso > 1 or !esp) { //No caigo en el caso especial
                forn(i, n) forn(j, col) if(v[i][j] != '#') v[i][j] = 'A';
                
                int pos = (uso > 1 ? 0 : n-1);
                int sum = (uso > 1 ? 1 : -1);
                while(uso) { //arriba para abajo
                    if(v[pos][col] == 'C') uso--;
                    if(v[pos][col] != '#') v[pos][col] = 'A';
                    pos+=sum;
                }
                return true;
            }
            else { //caso mas duro
                forr(i, 1, n) forr(j, col+1, m-1) {
                    if(v[i][j] == 'C' and v[i-1][j] != '#' and v[i][j+1] != '#' and v[i-1][j+1] != '#') {
                        forn(i, n) forn(j, col) if(v[i][j] != '#') v[i][j] = 'A';
                        forr(k, col, j+1) v[i][k] = 'A';
                        return true;
                    }
                }
            } 
        }
        return false;
    };

    auto hor = [&]() {
        int fila = 0, sum = 0;
        dfor(i, n) {
            sum += r[i];
            if(sum >= need) {
                fila = i;
                break;
            }
        }
        int uso = need - (sum - r[fila]);
        
        bool cond = v[n-1][0] == 'C' and v[n-1][1] == 'C' and v[n-1][m-2] == 'C' and v[n-1][m-1] == 'C';
        if(fila == n-1 and uso == r[fila] - 1 and cond) return false;

        for(int i = n-1; i > fila; i--) forn(j, m) if(v[i][j] != '#') v[i][j] = 'A';
        if(fila != n-1) {
            int izq = 0 + (n-1-fila), der = m-1 - (n-1-fila);
            while(uso) {
                if(v[fila][izq] == 'C') uso--;
                v[fila][izq] = 'A';
                if(uso){
                    if(v[fila][der] == 'C') uso--;
                    v[fila][der] = 'A';
                }
                izq++; der--;
            }   
        }
        else {
            if(uso == r[fila]) forn(i, m) v[fila][i] = 'A';
            else{
                int sum = (v[fila][0] == 'C' ? 1 : -1); 
                int pos = (v[fila][0] == 'C' ? 0 : m-1);
                while(uso) {
                    if(v[fila][pos] == 'C') uso--;
                    v[fila][pos] = 'A';
                    pos+=sum;
                }
            }
        }
        return true;
    };

    bool ok = hor();
    if(!ok) ok = vert();
    if(!ok){    
        forn(i, n) reverse(all(v[i]));
        reverse(all(c));
        ok = vert();
    }
    if(ok) {
        forn(i, n) forn(j, m) if(v[i][j] != '#' and v[i][j] != 'A') v[i][j] = 'B';
        forn(i, n) cout << v[i] << '\n';
    }
    else cout << "impossible\n";

    return 0;
}