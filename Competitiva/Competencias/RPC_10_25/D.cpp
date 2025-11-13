#include<bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define sz(a) ((int)(a.size()))
#define all(a) a.begin(), a.end()
#define dbg(x) cout << #x <<" "<< x << endl;
#define ws <<" "<<
#define nl cout << "\n";
typedef long long ll;

using namespace std;

vector<vector<int>> ps;
vector<vector<int>> v;
int n, m;

void cargarPrefixSum(){
    forr(i, 1, n + 1){
        forr(j, 1, m + 1){
            ps[i][j] = v[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }
}

int query(int x1, int y1, int x2, int y2){
    int ans = ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout); 
    #endif

    cin >> n >> m;
    ps.assign(n + 1, vector<int>(m + 1));
    v.assign(n + 1, vector<int>(m + 1));
    string s;
    forn(i, n) {
        cin >> s;
        forn(j, m) v[i][j] = s[j] - '0';
    }
    cargarPrefixSum();

/*     forn(i, n + 1){
        forn(j, m + 1) cout << v[i][j] << ' ';
        cout << '\n';
    } */

    int ans = 0;
    forn(i, n) forn(j, m){
        forr(k, i, n){
            int l = j - 1, r = m + 1;
            while(r - l > 1){
                int med = (l + r) / 2;
                if(query(i + 1, j + 1, k + 1, med + 1) == (k - i + 1) * (med - j + 1)) l = med;
                else r = med;

                /* dbg(query(i + 1, j + 1, k + 1, med + 1));
                cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << ' ' << med + 1 << '\n';
                cout << "---------------\n"; */
            }
            ans = max(ans, (l - j + 1) * (k - i + 1));
        }
    }

    cout << ans << '\n';

    return 0;
}