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
    
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n - 1), a(n);
        forn(i, n - 1) cin >> v[i];

        a[0] = 501;

        forr(i, 1, n){
            a[i] = a[i - 1] + v[i - 1];
        }

        forn(i, n) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}