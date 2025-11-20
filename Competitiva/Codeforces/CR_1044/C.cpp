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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]" << endl;}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    /* #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif */

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> tams(n);
        int tam = 0;
        forn(i, n){
            cout << "? " << i + 1 << ' ' << n << ' ';
            forn(j, n) cout << j + 1 << ' ';
            cout << endl;
            cin >> tams[i];
            tam = max(tam, tams[i]);
        }

        vector<vector<int>> m(tam);
        forn(i, n) m[tams[i] - 1].pb(i);
        
        int ind = tam - 1;
        int ini = m[ind][0];

        vector<int> ans{ini};
        forn(i, tam - 1){
            ind--;
            int res = 0;
            forn(j, sz(m[ind])){
                cout << "? " << ini + 1 << ' ' << 2 << ' ' << ini + 1 << ' ' << m[ind][j] + 1 << endl;
                cin >> res;
                if(res > 1){
                    ini = m[ind][j];
                    ans.pb(ini);
                    break;
                }
            }
        }

        cout << "! " << tam << ' ';
        for(int i : ans) cout << i + 1 << ' ';
        cout << endl;
    }

    return 0;
}