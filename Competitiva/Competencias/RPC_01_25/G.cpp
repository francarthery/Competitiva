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

    string s; cin >> s;

    bool flag = true;
    forr(i, 1, sz(s)) {
        if(s[i] > s[0]) {
            flag = true;
            break;
        }
        if(s[i] < s[0]) {
            flag = false;
            break;
        }
    }

    int res;
    if(flag){
        res = (s[0] - '0') * sz(s) + (10 - (s[0] - '0')) * (sz(s) - 1);
    }
    else {
        res = (s[0] - '0' - 1) * sz(s) + (10 - (s[0] - '0') + 1) * (sz(s) - 1);
    }

    cout << (sz(s) == 1 ? res + 1 : res) << '\n';

    
    return 0;
}