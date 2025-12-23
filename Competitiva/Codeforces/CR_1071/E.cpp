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

    int t; cin >> t;
    while(t--){
        int n, x, y; cin >> n >> x >> y;
        string s; cin >> s;
        vector<int> p(n);
        forn(i, n) cin >> p[i];

        bool flag = true;
        int pop = 0, npop = 0;
        for(char c : s) {
            if(c == '1') pop++;
            else npop++;
        }
        ll suma = accumulate(all(p), 0ll);

        if(suma > x + y) flag = false;
        
        int sumx = 0, sumy = 0;
        forn(i, n){
            if(s[i] == '0') sumx += (p[i] / 2) + 1;
            else sumy += (p[i] / 2) + 1;
        }
        if(sumx > x or sumy > y) flag = false;
        if(npop == 0 and pop > y - x or pop == 0 and npop > x - y) flag = false;
        
        //if(pop == 0 and x - y < sumx or npop == 0 and y - x < sumy) flag = false;

        cout << (flag ? "YES" : "NO") << '\n';
    }



    return 0;
}