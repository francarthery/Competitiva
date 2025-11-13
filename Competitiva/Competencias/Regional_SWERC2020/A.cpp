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

    int n, k; cin >> n >> k;
    map<string, ii> m;
    cin.ignore();
    forn(i, 3 * n){
        string s; getline(cin, s);
        m[s].fr++;
        m[s].sc = i;
    }

    vector<tuple<int, int, string>> v;
    for(auto i : m) v.pb({i.sc.fr, i.sc.sc, i.fr});

    sort(rall(v));
    forn(i, min(k, sz(v))){
        cout << get<2>(v[i]) << '\n';
    }


    return 0;
}