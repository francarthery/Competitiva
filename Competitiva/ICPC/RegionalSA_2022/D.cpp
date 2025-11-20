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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
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

    int n, h, w;
    char a, b;
    cin >> n >> h >> w;
    vector<ii> v(n);
    vector<pair<char, char>> res(n, pair<char, char>('N', 'N'));
    forn(i, n){
        cin >> a >> b;
        v[i].fr = a == 'Y';
        v[i].sc = b == 'Y';
    }

    forn(i, n){
        if(v[i].fr or !w) {
            w++; h--;
            res[i].fr = 'Y';
        }
        if(v[i].sc or !h){
            w--; h++;
            res[i].sc = 'Y';
        }
    }

    forn(i, n){
        cout << res[i].fr << ' ' << res[i].sc << '\n';
    }
    
    return 0;
}