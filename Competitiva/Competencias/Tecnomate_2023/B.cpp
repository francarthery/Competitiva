#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n, m, cont = 0;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));
    forn(i, n) forn(j, m) cin >> v[i][j];

    forn(i, n){
        forn(j, m - 2){
            if(v[i][j] == 'b' and v[i][j + 1] == 'u' and v[i][j + 2] == 'g') cont++;
            if(v[i][j] == 'g' and v[i][j + 1] == 'u' and v[i][j + 2] == 'b') cont++;
        }
    }
    forn(i, n - 2){
        forn(j, m){
            if(v[i][j] == 'b' and v[i + 1][j] == 'u' and v[i + 2][j] == 'g') cont++;
            if(v[i][j] == 'g' and v[i + 1][j] == 'u' and v[i + 2][j] == 'b') cont++;
        }
    }

    cout << cont << '\n';

    return 0;
}