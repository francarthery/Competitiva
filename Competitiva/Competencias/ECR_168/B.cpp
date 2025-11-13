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
        int cont = 0;
        vector<string> v(2);
        forn(i, 2) cin >> v[i];

        forr(i, 1, n - 1){
            if(v[0][i] == '.' and v[0][i + 1] == '.' and v[0][i - 1] == '.' and v[1][i] == '.' and v[1][i - 1] == 'x' and v[1][i + 1] == 'x') cont++;
        }
        forr(i, 1, n - 1){
            if(v[1][i] == '.' and v[1][i + 1] == '.' and v[1][i - 1] == '.' and v[0][i] == '.' and v[0][i - 1] == 'x' and v[0][i + 1] == 'x') cont++;
        }

        cout << cont << '\n';
    }
    
    return 0;
}