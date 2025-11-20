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
    cout << '['; for(auto c : v) cout << c << ','; cout << "\b]\n";
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

    int t;
    cin >> t;
    while(t--){
        int n, m, x = 0, y = 0;
        bool flag = false;
        cin >> n >> m;
        vector<string> v(n);
        forn(i, n) cin >> v[i];

        forn(i, n) {
            forn(j, m){
                if(v[i][j] == '#'){
                    int cont = i;
                    while(cont < n and v[cont][j] == '#') cont++;
                    y = j;
                    x = (cont + i - 1) / 2;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        cout << x + 1 << ' ' << y + 1 << '\n';
        
    }
    
    return 0;
}