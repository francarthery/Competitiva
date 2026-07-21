#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend9)()
#define dbg(x) cout<<#x <<" = " << x << endl;
#define vdbg(x) {cout<<#x<<" = ["; for(auto e : x) cout<<e<<' '; cout<<"\n";}
#define nl cout<<"\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif
    int n, m, q; cin >> n >> m >> q;

    vector<int> wu(n);
    forn(i, n) cin >> wu[i];
    unordered_map<string, int> bolsa;

    forn(i, m){
        string s; cin >> s;
        bolsa[s]++;
    }

    //for(auto [x, y] : bolsa) cout << x << ' ' << y << '\n';
    vector<string> palabritas;
    
    function<void(string &)> solve = [&] (string s){
        if(sz(s) == n){
            palabritas.push_back(s);
            return;
        }

        s+= "1";
        solve(s);
        s.pop_back();
        s+= "0";
        solve(s);
        s.pop_back();
    };

    string s;
    solve(s);

    unordered_map<string, vector<int>> precalc;
    forn(i, sz(palabritas)) precalc[palabritas[i]].resize(101);

    forn(i, sz(palabritas)){
        for(auto [x, y] : bolsa){
            int sum = 0;
            forn(j, n){
                if(x[j] == palabritas[i][j]) sum+= wu[j];
            }
            // dbg(x);
            // // dbg(y);
            // dbg(palabritas[i]);
            // dbg(sum);
            if(sum <= 100) precalc[palabritas[i]][sum]+= y;
            // dbg(precalc[palabritas[i]][sum]);
            // cout << '\n';

        }
    }

    //dbg(precalc["00"][40]);
    // dbg(precalc["00"][0]);
    unordered_map<string, vector<ll>> ps;

    forn(i, sz(palabritas)) ps[palabritas[i]].resize(102);

    for(auto [x, y] : precalc){
        ps[x][0] = y[0];
        forr(i, 1, 101){
            ps[x][i] += ps[x][i - 1] + y[i];
        }
    }
    while(q--){
        string x; cin >> x;
        int k; cin >> k;
        cout << ps[x][k] << '\n';
    }
    return 0;
}