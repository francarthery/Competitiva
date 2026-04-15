#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define dbg(x) cout<< #x <<" = "<< x<< endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef chichu
        freopen("in", "r", stdin);
        freopen("out" ,"w", stdout);
    #endif

    int n, m, k; cin >> n >> m >> k;
    map<int, vector<int>> ver, hor;
    int a, b; 
    forn(i, k) {
        cin >> a >> b;
        ver[a].push_back(b);
        hor[b].push_back(a);
    }

    int ma = 0;
    ii sol = {0,0};

    for(auto &i : ver) {
        auto &v = i.second;
        v.push_back(m+1);
        v.push_back(0);
        sort(all(v));
        int ant = -1;
        forn(j, sz(v)){
            if(v[j] != ant+1 and sz(v) - j > ma) {
                ma = sz(v) - j - 1;
                sol = {i.first, v[j] - 1};
            }
            ant = v[j];
        } 

        ant = m+2;
        dfor(j, sz(v)){
            if(v[j] != ant-1 and j+1 > ma) {
                ma = j;
                sol = {i.first, v[j] + 1};
            }
            ant = v[j];
        } 
    }

    for(auto &i : hor) {
        auto &v = i.second;
        v.push_back(n+1);
        v.push_back(0);
        sort(all(v));
        int ant = -1;
        forn(j, sz(v)){
            if(v[j] != ant+1 and sz(v) - j > ma) {
                ma = sz(v) - j - 1;
                sol = {v[j] - 1, i.first};
            }
            ant = v[j];
        } 

        ant = n+2;
        dfor(j, sz(v)){
            if(v[j] != ant-1 and j+1 > ma) {
                ma = j;
                sol = {v[j] + 1, i.first};
            }
            ant = v[j];
        } 
    }

    cout << ma << '\n';
    cout << sol.first << ' ' << sol.second << '\n';

    return 0;
}