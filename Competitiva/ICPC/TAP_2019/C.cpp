#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "\b]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

vector<vector<char>> v;
int n, m, ans = 0, izq, der, arr, aba;

int expy(int x, int y, int val){
    int rta = 0;
    x+= val;
    while(x >= 0 and x < n  and v[x][y] != '.'){
        if(v[x][y - 1] == '*' or v[x][y + 1] == '*') return -1;
        else rta++;
        x+= val;
    }
    return rta;
}

int expx(int x, int y, int val){
    int rta = 0;
    y+= val;
    while(y >= 0 and y < m and v[x][y] != '.'){
        if(v[x - 1][y] == '*' or v[x + 1][y] == '*') return -1;
        else rta++;
        y+= val;
    }
    return rta;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n >> m;

    v.assign(n, vector<char> (m));

    forn(i, n) forn(j, m) cin >> v[i][j];
    forr(i, 1, n - 2) forr(j, 1, m - 1){
        if(v[i][j] == '*' and v[i + 1][j] == '*' and v[i - 1][j] == '*' and v[i][j + 1] == '*' and v[i][j - 1] == '*'){
            izq = expx(i, j, -1);
            der = expx(i, j, 1);
            if(izq == der and izq != -1){
                arr = expy(i, j, -1);
                aba = expy(i, j, 1);
                if(arr == izq and aba > izq) ans++;
            }
        }
    }

    cout << ans << '\n';



    
    return 0;
}