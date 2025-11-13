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

vector<string> v;
void pt(int ii, int jj){
    forn(i, 5) v[ii - i][jj] = '.';
    v[ii - 4][jj - 1] = v[ii - 4][jj] = v[ii - 4][jj + 1] = '.'; 
} 

void pp(int ii, int jj){
    forn(i, 5) v[ii - i][jj] = '.';
    v[ii - 4][jj + 1] = v[ii - 4][jj + 2] = v[ii - 2][jj + 1] = v[ii - 2][jj + 2] = v[ii - 3][jj + 2] = '.'; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, t = 0, a = 0, p = 0;
    cin >> n >> m;
    v.resize(n);
    forn(i, n) cin >> v[i];
    dfor(i, n) forn(j, m){
        if(v[i][j] == '#'){
            if(v[i - 2][j + 1] == '.') {
                pt(i, j);
                t++;
            }
            else{
                pp(i, j);//p
                if(v[i][j + 2] == '#') {v[i][j + 2] = '.'; v[i - 1][j + 2] = '.'; a++;} //a
                else p++;
            }
        }
    }

    cout << t << ' ' << a << ' ' << p << '\n';
    
    return 0;
}