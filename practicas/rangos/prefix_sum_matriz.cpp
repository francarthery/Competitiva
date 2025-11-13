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

    int n, m, rta = 1;
    cin >> n >> m;
    vector<string> p(n);
    vector<vector<bool>> v(n, vector<bool>(m));
    vector<vector<int>> pref(n + 1, vector<int>(m + 1));
    forn(i, n) cin >> p[i];

    forn(i, n) forn(j, m - 1) if(p[i][j] != p[i][j + 1]) v[i][j + 1] = true;
    //Prefix sum matrices
    forr(i, 1, n + 1) forr(j, 1, m + 1) pref[i][j] += pref[i][j - 1] + v[i - 1][j - 1];
    forr(j, 1, m + 1) forr(i, 1, n + 1) pref[i][j] += pref[i - 1][j];
    auto f = [&](int &i1, int &j1, int &i2, int &j2) { 
        return pref[i2 + 1][j2 + 1] - pref[i2 + 1][j1] - pref[i1][j2 + 1] + pref[i1][j1]; 
    };

    forn(i, n) forr(j, 1, m){
        int temp = 1;
        if(i < n - 1 and !v[i][j] and !v[i + 1][j]){
            temp = 4;
            int i2 = i + 2, j2 = j + 1;
            while(i2 < n and j2 < m){
                if(!f(i, j, i2, j2)) temp += (i2 - i + 1) * 2 - 1;
                i2++, j2++;
            }
        }

        rta = max(rta, temp);
    }

    //forn(j, n) vdbg(v[j]);
    cout << rta << '\n';
    
    return 0;
}