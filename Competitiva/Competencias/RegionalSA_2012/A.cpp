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

    int n, b; 
    while(cin >> n >> b and (n or b)){
        vector<int> l(n + 2), r(n + 2);
        forn(i, n + 1) r[i] = i + 1;
        for(int i = n + 1; i > 0; i--) l[i] = i - 1;

        //vdbg(l); vdbg(r);
        int x, y;
        forn(i, b){
            cin >> x >> y;
            int nx = l[x];
            int ny = r[y];
            r[nx] = ny;
            l[ny] = nx;

            if(nx == 0) cout << "* ";
            else cout << nx << ' ';
        
            if(ny == n + 1) cout << "*\n";
            else cout << ny << '\n';
        }

        cout << '-' << '\n';
    }

    return 0;
}