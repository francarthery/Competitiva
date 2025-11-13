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
        freopen("output.out", "w", stdout);
    #endif

    int h, w, s1, s2;
    cin >> h >> w >> s1 >> s2;
    vector<vector<char>> v(h, vector<char>(w));
    forn(i, h) forn(j, w) cin >> v[i][j];
    string s;
    cin >> s;
    s1--; s2--;
    for(char & c : s){
        if(c == 'R' and s2 < w - 1 and v[s1][s2 + 1] != '#') s2++;
        if(c == 'L' and s2 > 0 and v[s1][s2 - 1] != '#') s2--;
        if(c == 'D' and s1 < h - 1 and v[s1 + 1][s2] != '#') s1++;
        if(c == 'U' and s1 > 0 and v[s1 - 1][s2] != '#') s1--;
    }

    cout << s1 + 1 << ' ' << s2 + 1 << '\n';

    
    return 0;
}