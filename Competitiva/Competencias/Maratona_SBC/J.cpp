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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int k, l, n, m, rta = -1, rx, ry;
    cin >> n >> m >> k >> l;
    vector<string> v(n);
    vector<vector<int>> atack(n, vector<int>(m)); //Almacena a cuantos peones puede atacar esa pos
    forn(i, n) cin >> v[i];
    k--; l--;

    forn(i, n){
        forn(j, m){
            if(v[i][j] == '*'){ //Los dos del medio solo se hacen si las dim del cuadrado son mas de 1
                atack[i][j] = -1;
                if(i + k < n and j + l < m and v[i + k][j + l] != '*') atack[i + k][j + l]++; 
                if(i - k >= 0 and j + l < m and k and l and v[i - k][j + l] != '*') atack[i - k][j + l]++; 
                if(i + k < n and j - l >= 0 and k and l and v[i + k][j - l] != '*') atack[i + k][j - l]++; 
                if(i - k >= 0 and j - l >= 0 and v[i - k][j - l] != '*') atack[i - k][j - l]++; 

                if(l != k){
                    if(i + l < n and j + k < m and v[i + l][j + k] != '*') atack[i + l][j + k]++; 
                    if(i - l >= 0 and j + k < m and k and l and v[i - l][j + k] != '*') atack[i - l][j + k]++; 
                    if(i + l < n and j - k >= 0 and k and l and v[i + l][j - k] != '*') atack[i + l][j - k]++; 
                    if(i - l >= 0 and j - k >= 0 and v[i - l][j - k] != '*') atack[i - l][j - k]++; 
                }
            }
        }
    }

    forn(i, n) forn(j, m) {
        if(atack[i][j] > rta){
            rta = atack[i][j];
            rx = i; ry = j;
        }
    }

    cout << rx + 1 << ' ' << ry + 1 << '\n';    
    
    return 0;
}