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

    int t, n, x, y;
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        bool flag = true;
        int tam = x - y + 1;
        vector<int> sol(n);

        for(int i = y - 2; i >= 0; i--){
            sol[i] = (flag ? -1 : 1);
            flag = !flag;
        }
        forr(i, y - 1, x) sol[i] = 1;
        
        flag = true;
        for(int i = x; i < n; i++){
            sol[i] = (flag ? -1 : 1);
            flag = !flag;
        }

        forn(i, n) cout << sol[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}