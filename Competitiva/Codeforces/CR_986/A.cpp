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

    int t, n, a, b;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        string s;
        cin >> s;
        map<char, pair<int, int>> m{{'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}};

        int px = 0, py = 0;
        bool flag = false;
        forn(i, 100){
            for(char c : s){
                px += m[c].fr;
                py += m[c].sc;

                if(px == a and py == b) {
                    flag = true;
                    break;
                }
            }
            if(px == a and py == b) {
                    flag = true;
                    break;
                }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }


    
    return 0;
}   