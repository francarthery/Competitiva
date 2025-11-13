#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    int a, b, c;
    cin >> a >> b >> c;

    vector<bool> v(8);

    v[a] = true;
    v[b] = true;
    v[c] = true;

    if(v[1] and v[2]) cout << "S\n";
    else if(v[1] and v[3]) cout << "S\n";
    else if(v[2] and v[3] and v[4]) cout << "S\n";
    else if(v[1] and v[4] and v[5]) cout << "S\n";
    else cout << "N\n";

    return 0;
}