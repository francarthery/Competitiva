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
    
    long long res, n, m;
    cin >> m;

    while(m--){
        cin >> n;
        res = (n * (n + 1) * (2 * n + 1)) / 6 + (n * (n - 1)) / 2;

        cout << res << '\n';
    }

    return 0;
}