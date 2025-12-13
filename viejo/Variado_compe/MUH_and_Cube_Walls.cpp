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

vector<int> z;

void zfunc(vector<int> &s){
    int x = 0, y = 0, n = s.size();
    z.resize(n);
    forr(i, 1, n){
        z[i] = (y < i) ? 0 : min(y - i + 1, z[i - x]);
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > y){
            x = i; y = i + z[i] - 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, w, cont = 0;
    cin >> n >> w;

    if(w > 1){
        vector<int> v1(n), v2(w), s(n + w - 1);
        forn(i, n) cin >> v1[i];
        forn(i, w) cin >> v2[i];
        forn(i, n - 1) s[i + w] = v1[i] - v1[i + 1];
        forn(i, w - 1) s[i] = v2[i] - v2[i + 1];
        s[w - 1] = 1e9 + 7;
        zfunc(s);
        vdbg(s);

        forr(i, w, s.size()) if(z[i] == w - 1) cont++;
    }
    else cont = n;
    cout << cont << '\n';

    return 0;
}