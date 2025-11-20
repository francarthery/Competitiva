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

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        string st;
        cin >> st;

        bool p = false, s = false, flag = true;
        for(char &c : st){
            if(c == 'p') p = true;
            if(c == 's' and p) flag = false;
        }

        p = false;
        forr(i, 1, n - 1){
            if(st[i] == 's') s = true;
            else if(st[i] == 'p') p = true;
            if((s and st[i] == 'p') or (p and st[i] == 's')) flag = false;
        }
        cout << (flag ? "YES" : "NO") << '\n';

    }


    
    return 0;
}