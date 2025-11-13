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
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int n, m, x, y, ma = INT_MIN, maxvec = 0, sum;
    cin >> n >> m;
    vector<vector<int>> v(m, vector<int>());
    forn(i, n){
        cin >> x >> y;
        v[x - 1].pb(y);
    }

    forn(i, m){
        sort(v[i].rbegin(), v[i].rend()); //Ordeno todos los vectores
        forr(j, 1, sz(v[i])) v[i][j] += v[i][j - 1]; //Prefix sum
        while(!v[i].empty() and v[i].back() <= 0) v[i].pop_back(); //Saco negativos
        maxvec = max(maxvec, sz(v[i])); //Calculo vector mas largo
    }

    sort(all(v), [](vector<int> &a, vector<int> &b) {return sz(a) > sz(b);});
    
    forn(i, maxvec){
        sum = 0;
        forn(j, m){
            if(sz(v[j]) < i + 1) break; //Si ya no llego salgo
            sum += v[j][i];
        }
        ma = max(ma, sum);
    }

    cout << max(0, ma) << '\n';
    
    return 0;
}