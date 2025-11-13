#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int t, n, k, x, ma;
    cin >> t;

    while(t--){
        cin >> n >> k;
        map<int, int> m;
        ma = 0;
        forn(i, n){
            cin >> x;
            m[x]++;
        }

        forall(it, m){
            ma = max(it -> second, ma);
        }

        if(k > ma) cout << n;
        else cout << k - 1;
        cout << '\n';
    }

    return 0;
}