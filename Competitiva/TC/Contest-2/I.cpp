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
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, x;
    ll cont = 0;
    bool flag = true, hacer = false;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    forn(i, n) forn(j, m){
        cin >> x;
        v[i][j] = x;
        if(!x) hacer = true;
        cont += x;
    }
    if(hacer){
        for(int i = n - 2; flag and i > 0; i--){
            for(int j = m - 2; flag and j > 0; j--){
                if(v[i][j] == 0){
                    v[i][j] = min(v[i + 1][j], v[i][j + 1]) - 1;
                    cont += v[i][j];
                }
                if(v[i][j] <= v[i - 1][j] or v[i][j] <= v[i][j - 1]) flag = false;
            }
        }
    }

    forn(i, n - 1) forn(j, m - 1)
        if(v[i][j] >= v[i][j + 1] or v[i][j] >= v[i + 1][j]) flag = false;
    if(v[n - 1][m - 1] <= v[n - 2][m - 1] or v[n - 1][m - 1] <= v[n - 1][m - 2]) flag = false;

    cout << (flag ? cont : -1) << '\n';
    
    return 0;
}